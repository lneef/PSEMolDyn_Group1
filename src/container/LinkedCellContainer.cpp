//
// Created by lukas on 29.11.22.
//

#include <numeric>
#include <cmath>
#include <iostream>
#include "LinkedCellContainer.h"
#include "ParticleContainer.h"
#include "Reflecting.h"
#include "MolSimLogger.h"
#include "Periodic.h"

void LinkedCellContainer::apply(std::function<void(Particle &)> fun) {
    for (size_t i = mesh[0] + 1; i < cells.size() - mesh[0] - 1; ++i) {
        cells[i].apply(fun);

        if (i % mesh[0] == mesh[0] - 2)
            i += 2;
    }
}

void LinkedCellContainer::applyX(std::function<void(Particle &)> fun) {
    apply(fun);
    update();

}

void LinkedCellContainer::clearHalo() {
    for (auto &cell: halo)
        cell.get().clear();
}

void LinkedCellContainer::update() {
    size_t len = cells.size() - mesh[0] - 1;
    for (size_t i = mesh[0] + 1; i < len; ++i) {
        for (auto it = cells[i].begin(); it != cells[i].end();) {
            auto &p = *it;
            size_t ind = index(p);
            auto &pos = p.getX();

            //check that not completely outside
            if (pos[0] < -rcutoff || pos[0] >= domain[0] + rcutoff || pos[1] < -rcutoff ||
                pos[1] > domain[1] + rcutoff) {
                SPDLOG_LOGGER_DEBUG(MolSimLogger::logger(), "Particle at position ({}, {}, {}) removed", p.getX()[0],
                                    p.getX()[1], p.getX()[2]);
                it = cells[i].remove(it);
                continue;
            }
            //check if in the right cell
            if (ind == i) {
                ++it;
                continue;
            }
            //add to new cell
            update(p, ind);

            //remove from old cell
            it = cells[i].remove(it);
        }

        if (i % mesh[0] == mesh[0] - 2)
            i += 2;
    }

    clearHalo();
}

size_t LinkedCellContainer::size() {
    size_t len = std::accumulate(cells.begin(), cells.end(), 0,
                                 [](int len, ParticleContainer &p) { return len + p.size(); });
    return len;

}

void LinkedCellContainer::applyFBoundary(Reflecting cond, std::function<void(Particle &, Particle &)> &fun) {
    for (auto &list: boundary) {
        for (auto &p: list.get()) {
            if (cond.check(p))
                cond.apply(p, fun);
        }
    }
}


void LinkedCellContainer::applyF(std::function<void(Particle &, Particle &)> fun) {
    size_t len = cells.size() - mesh[0] - 1;
    size_t i = mesh[0] + 1;
    for (; i < len; ++i) {
        auto &cell = cells[i];
        cell.applyF(fun);
        for (auto &p: cell) {
            auto partial = [&p, &fun](Particle &p2) { fun(p, p2); };

            //check if right neighbour exists
            rightNeighbour(i, partial, p, fun);

            //check if upper neighbour exists
            upperNeighbour(i, partial, len, p, fun);

            //check if upper right neighbour exists
            upperRightNeighbour(i, partial, len, p, fun);

            //check is upper left neighbour exists
            upperLeftNeighbour(i, partial, len, p, fun);
        }

        if (i % mesh[0] == mesh[0] - 2)
            i += 2;
    }

    for (auto &cond: conditions)
        applyFBoundary(cond, fun);

}

size_t LinkedCellContainer::index(Particle &p) {
    auto &pos = p.getX();
    size_t x_ind, y_ind;

    if (pos[0] >= domain[0]) {
        x_ind = mesh[0] - 1;
    } else {
        x_ind = static_cast<size_t>(floor(pos[0] / rcutoff)) + 1;
    }

    if (pos[1] >= domain[1]) {
        y_ind = (mesh[1] - 1) * mesh[0];
    } else {
        y_ind = static_cast<size_t>(floor(pos[1] / rcutoff)) * mesh[0] + mesh[0];
    };
    return x_ind + y_ind;
}

void LinkedCellContainer::addParticle(Particle &&p) {
    Particle p1 = p;
    size_t ind = index(p1);
    auto &pos = p.getX();
    if (0 <= pos[0] && pos[0] < domain[0] && 0 <= pos[1] && pos[1] < domain[1] && inside3D(p1)) {
        cells[ind].addParticle(p);
    }
}

std::vector<ParticleContainer> &LinkedCellContainer::getCells() {
    return cells;
}

void LinkedCellContainer::setUp() {
    size_t i = 0;
    size_t len = cells.size();

    //add first row of halo cells
    for (; i < mesh[0]; ++i)
        halo.emplace_back(std::ref(cells[i]));

    //additional halo cell on the left sie
    halo.emplace_back((std::ref(cells[i])));
    ++i;

    //add all boundary cell in the bottom boundary
    size_t j = i;
    for (; j < i + mesh[0] - 2; ++j)
        boundary.emplace_back(std::ref(cells[j]));
    i = j;

    //add halo cell at the right border
    halo.emplace_back(std::ref(cells[i]));
    ++i;

    //add right and left halo cell as well as right an left boundary cell
    //or nothing if mesh[1] = 1
    for (; i < len - 2 * mesh[0]; ++i) {
        //right or left halo cell
        if (i % mesh[0] == 0 || i % mesh[0] == mesh[0] - 1) {
            halo.emplace_back(std::ref((cells[i])));
            continue;
        }

        //right or left boundary cell
        //if mesh[0] only middle cell
        if (i % mesh[0] == 1 || i % mesh[0] == mesh[0] - 2)
            boundary.emplace_back(std::ref(cells[i]));
    }

    //add halo cell at left boundary from last boundary row
    //or left halo cell of uppest row if mesh[1] = 1
    halo.emplace_back(std::ref(cells[i]));
    ++i;

    //add upper boundary cells or nothing if mesh[1] = 1
    j = i;
    for (; j < len - mesh[0] - 1; ++j)
        boundary.emplace_back(std::ref(cells[j]));
    i = j;

    //add halo cell at right border or halo cell in the middle if mesh[1] = 1
    halo.emplace_back(std::ref(cells[i]));
    ++i;

    //add halo cells at upper border
    for (; i < len; ++i)
        halo.emplace_back(std::ref(cells[i]));
}

void LinkedCellContainer::setRCutOff(double rcutoff_arg) {
    rcutoff = rcutoff_arg;
}

void LinkedCellContainer::setDomain(std::array<double, 3> &domain_arg) {
    domain = domain_arg;
}

void LinkedCellContainer::setSize(double rcutoff_arg, std::array<double, 3> &domain_arg, size_t dim) {
    setRCutOff(rcutoff_arg);
    setDomain(domain_arg);
    for (size_t i = 0; i < dim; ++i) {
        mesh[i] = ceil(std::abs(domain_arg[i]) / rcutoff_arg) + 2;
    }
    size_t len = 1;
    for (size_t i = 0; i < dim; ++i) {
        len *= mesh[i] == 0 ? 1 : mesh[i];
    }
    cells.resize(len);
    setUp();
}


const std::vector<std::reference_wrapper<ParticleContainer>> &LinkedCellContainer::getHalo() const {
    return halo;
}

const std::vector<std::reference_wrapper<ParticleContainer>> &LinkedCellContainer::getBoundary() const {
    return boundary;
}

void LinkedCellContainer::addReflecting(Reflecting( &&reflecting)) {
    conditions.emplace_back(reflecting);
}

std::array<double, 3> &LinkedCellContainer::getDomain() {
    return domain;
}

LinkedCellContainer::LinkedCellContainer() = default;

LinkedCellContainer::~LinkedCellContainer() = default;

bool LinkedCellContainer::inside3D(Particle &p) {
    auto &pos = p.getX();
    return Particle::comp(0, domain[2]) || ((0 < pos[2] || Particle::comp(pos[2], 0)) && pos[2] < domain[2]);
}

void LinkedCellContainer::rightNeighbour(size_t i, const std::function<void(Particle &)> &partial, Particle &p,
                                         std::function<void(Particle &, Particle &)> &fun) {

    Periodic cond{};
    if ((i + 2) % mesh[0] > 0) {
        auto &neighbour = cells[i + 1];
        neighbour.apply(partial);
    } else if (periodic.contains(2) || periodic.contains(4)) {
        cond.hor(-domain[0]);
        cond.apply(cells[i - mesh[0] + 3], p, fun);
    }
}

void
LinkedCellContainer::upperNeighbour(size_t i, const std::function<void(Particle &)> &partial, size_t len, Particle &p,
                                    std::function<void(Particle &, Particle &)> &fun) {
    if (i + mesh[0] < len) {
        auto &neighbour = cells[i + mesh[0]];
        neighbour.apply(partial);
    } else if (periodic.contains(1) || periodic.contains(3)) {
        Periodic cond{};
        cond.vert(-domain[1]);
        size_t index = i % mesh[0] + mesh[0];
        cond.apply(cells[index], p, fun);
    }
}

void LinkedCellContainer::upperLeftNeighbour(size_t i, const std::function<void(Particle &)> &partial, size_t len,
                                             Particle &p, std::function<void(Particle &, Particle &)> &fun) {
    Periodic cond{};
    size_t critical = cells.size() - 2 * mesh[0];
    if (i + mesh[0] - 1 < len && (i - 1) % mesh[0] > 0) {
        auto &neighbour = cells[i + mesh[0] - 1];
        neighbour.apply(partial);
    } else if (periodic.contains(4) && i < critical) {
        cond.hor(domain[0]);
        size_t ind = i + mesh[0] + mesh[0] - 3;
        cond.apply(cells[ind], p, fun);
    } else if (periodic.contains(3) && i > critical + 1) {
        cond.vert(-domain[1]);
        size_t ind = i % mesh[0] - 1 + mesh[0];
        cond.apply(cells[ind], p, fun);
    } else if ((periodic.contains(3) || periodic.contains(4)) && i == critical + 1) {
        cond.hor(domain[0]);
        cond.vert(-domain[1]);
        cond.apply(cells[2 * mesh[0] - 2], p, fun);
    }
}

void LinkedCellContainer::upperRightNeighbour(size_t i, const std::function<void(Particle &)> &partial, size_t len,
                                              Particle &p, std::function<void(Particle &, Particle &)> &fun) {
    Periodic cond{};
    size_t critical = cells.size() - 2 * mesh[0];
    if (i + mesh[0] + 1 < len && (i + 2) % mesh[0] > 0) {
        auto &neighbour = cells[i + mesh[0] + 1];
        neighbour.apply(partial);
    } else if (periodic.contains(2) && i < critical) {
        cond.hor(-domain[0]);
        cond.apply(cells[i + 3], p, fun);
    } else if (periodic.contains(3) && i < critical + mesh[0] - 2) {
        cond.hor(-domain[0]);
        size_t ind = i % mesh[0] + 1 + mesh[0];
        cond.apply(cells[ind], p, fun);
    } else if ((periodic.contains(2) || periodic.contains(3)) && i == critical + mesh[0] - 2) {
        cond.hor(-domain[0]);
        cond.vert(-domain[1]);
        cond.apply(cells[mesh[0] + 1], p, fun);
    }

}

void LinkedCellContainer::addPeriodic(int bound) {
    periodic.emplace(bound);
}

bool LinkedCellContainer::side(size_t ind) {
    return (ind % mesh[0] == 0 && periodic.contains(4)) || (ind % mesh[0] == mesh[0] - 1 && periodic.contains(2)) ||
           (ind < mesh[0] && periodic.contains((1))) || (ind > cells.size() - mesh[0] && periodic.contains(3));
}

size_t LinkedCellContainer::mirror(Particle &p, size_t ind) {

    if (ind % mesh[0] == 0) {
        std::array<double, 3> to_add{};
        to_add[0] = domain[0];
        p.setX(p.getX() + to_add);
        ind = index(p);
    }

    if (ind % mesh[0] == mesh[0] - 1) {
        std::array<double, 3> to_add{};
        to_add[0] = -domain[0];
        p.setX(p.getX() + to_add);
        ind = index(p);
    }

    if (ind < mesh[0]) {
        std::array<double, 3> to_add{};
        to_add[1] = domain[1];
        p.setX(p.getX() + to_add);
        ind = index(p);
    }

    if (ind >= cells.size() - mesh[0]) {
        std::array<double, 3> to_add{};
        to_add[1] = -domain[1];
        p.setX(p.getX() + to_add);
        ind = index(p);
    }

    return ind;
}

void LinkedCellContainer::update(Particle &p, size_t ind) {
    if (side(ind)) {
        ind = mirror(p, ind);
    }
    cells[ind].addParticle(p);

}