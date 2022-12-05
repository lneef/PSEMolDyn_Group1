//
// Created by lukas on 29.11.22.
//

#include <numeric>
#include <cmath>
#include <iostream>
#include "LinkedCellContainer.h"
#include "ParticleContainer.h"
#include "Reflecting.h"

void LinkedCellContainer::apply(std::function<void(Particle &)> fun) {
    for (auto &list: cells) {
        list.apply(fun);
    }
}

void LinkedCellContainer::applyX(std::function<void(Particle &)> fun) {
    apply(fun);
    update();

}

void LinkedCellContainer::clearHalo(){
    halo.clear();
}

void LinkedCellContainer::update() {
    size_t len = cells.size();
    for (size_t i = 0; i < len; ++i) {
        for (auto it = cells[i].begin(); it != cells[i].end();) {
            auto &p = *it;
            size_t ind = index(p);
            auto &pos = p.getX();
            if (pos[0] < 0 || pos[0] >= domain[0] || pos[1] < 0 || pos[1] > domain[1]) {
                halo.addParticle(p);
                it = cells[i].remove(it);
                continue;
            }
            if (ind == i) {
                ++it;
                continue;
            }
            addParticle(p);
            it = cells[i].remove(it);
        }
    }

    clearHalo();
}

size_t LinkedCellContainer::size() {
    size_t len = std::accumulate(cells.begin(), cells.end(), 0,
                                 [](int len, ParticleList &p) { return len + p.size(); });
    return len;

}

void LinkedCellContainer::applyFBoundary( Reflecting cond,
                                         std::function<void(Particle &, Particle &)> &fun) {
    for (auto &list: boundary) {
        for (auto &p: list.get()) {
            if (cond.check(p))
                cond.apply(p, fun);
        }
    }
}


void LinkedCellContainer::applyF(std::function<void(Particle &, Particle &)> fun) {
    size_t len = cells.size();
    size_t i = 0;
    for (; i < len; ++i) {
        auto &cell = cells[i];
        cell.applyF(fun);
        for (auto &p: cell) {
            auto partial = [&p, &fun](Particle &p2) { fun(p, p2); };

            if ((i + 1) % mesh[0] > 0) {
                auto &neighbour = cells[i + 1];
                neighbour.apply(partial);
            }

            if (i + mesh[0] < len) {
                auto &neighbour = cells[i + mesh[0]];
                neighbour.apply(partial);
            }

            if (i + mesh[0] + 1 < len) {
                auto &neighbour = cells[i + mesh[0] + 1];
                neighbour.apply(partial);
            }

            if (i + mesh[0] - 1 < len && i % mesh[0] > 0) {
                auto &neighbour = cells[i + mesh[0] - 1];
                neighbour.apply(partial);
            }
        }
    }

    for (auto &cond: conditions)
        applyFBoundary(cond, fun);

}

size_t LinkedCellContainer::index(Particle &p) {
    auto &pos = p.getX();
    size_t x_ind = floor(pos[0] / rcutoff);
    size_t y_ind = floor(pos[1] / rcutoff) * mesh[0];
    return x_ind + y_ind;
}

void LinkedCellContainer::addParticle(Particle &p) {
    size_t ind = index(p);
    auto &pos = p.getX();
    if (0 <= pos[0] && pos[0] < domain[0] && 0 <= pos[1] && pos[1] < domain[1])
        cells[ind].addParticle(p);
}

void LinkedCellContainer::addParticle(Particle &&p) {
    Particle p1 = p;
    size_t ind = index(p1);
    auto &pos = p.getX();
    if (0 <= pos[0] && pos[0] < domain[0] && 0 <= pos[1] && pos[1] < domain[1]) {
        cells[ind].addParticle(p);
    }
}

std::vector<ParticleList> LinkedCellContainer::getCells() {
    return cells;
}

void LinkedCellContainer::setUpBoundary() {
    size_t i = 0;
    for (; i < mesh[0]; ++i) {
        boundary.emplace_back(std::ref(cells[i]));
    }
    for (; i < cells.size() - mesh[0]; i++) {
        if (i % mesh[0] == 0 || i % mesh[0] == mesh[0] - 1)
            boundary.emplace_back(std::ref(cells[i]));
    }

    for (; i < cells.size(); ++i) {
        boundary.emplace_back(std::ref(cells[i]));
    }
}

void LinkedCellContainer::setRCutOff(double rcutoff_arg) {
    rcutoff = rcutoff_arg;
}

void LinkedCellContainer::setDomain(std::array<double, 3> &domain_arg) {
    domain = domain_arg;
}

void LinkedCellContainer::setSize(double rcutoff_arg, std::array<double, 3> &domain_arg) {
    setRCutOff(rcutoff_arg);
    setDomain(domain_arg);
    for (size_t i = 0; i < 3; ++i) {
        mesh[i] = ceil(std::abs(domain_arg[i]) / rcutoff_arg);
    }
    size_t len = 1;
    for (size_t i = 0; i < 3; ++i) {
        len *= mesh[i] == 0 ? 1 : mesh[i];
    }
    cells.resize(len);
    setUpBoundary();
}

std::vector<ParticleList> &LinkedCellContainer::get() {
    return cells;
}


const ParticleContainer &LinkedCellContainer::getHalo() const {
    return halo;
}

const std::vector<std::reference_wrapper<ParticleList>> &LinkedCellContainer::getBoundary() const {
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
