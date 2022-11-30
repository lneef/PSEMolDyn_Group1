//
// Created by lukas on 29.11.22.
//

#include <numeric>
#include <cmath>
#include <iostream>
#include "LinkedCellContainer.h"

void LinkedCellContainer::apply(std::function<void(Particle &)> fun) {
    for (auto &list: cells) {
        list.apply(fun);
    }
}

void LinkedCellContainer::applyX(std::function<void(Particle &)> fun) {
    apply(fun);
    update();

}

void LinkedCellContainer::update() {
    size_t len = cells.size();
    for (int i = 0; i < len; ++i) {
        for (auto it = cells[i].begin(); it != cells[i].end();) {
            auto &p = *it;
            int ind = index(p);
            if (ind == i) {
                ++it;
                continue;
            }
            addParticle(p);
            it = cells[i].remove(it);

        }
    }
}

size_t LinkedCellContainer::size() {
    size_t len = std::accumulate(cells.begin(), cells.end(), 0,
                                 [](int len, ParticleList &p) { return len + p.size(); });
    return len;

}

void LinkedCellContainer::applyF(std::function<void(Particle &, Particle &)> fun) {
    size_t len = cells.size();
    for (size_t i = 0; i < len; ++i) {
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

        }
    }

}

int LinkedCellContainer::index(Particle &p) {
    auto &pos = p.getX();

    int ind = floor(std::abs(pos[0]) / rcutoff) + floor(std::abs(pos[1]) / rcutoff) * mesh[0] +
              floor(std::abs(pos[2]) / rcutoff) * mesh[0] * mesh[1];
    return ind;
}

void LinkedCellContainer::addParticle(Particle &p) {
    int ind = index(p);
    if(ind < cells.size())
        cells[ind].addParticle(p);
}

void LinkedCellContainer::addParticle(Particle &&p) {
    Particle p1 = p;
    int ind = index(p1);
    if(ind < cells.size())
        cells[ind].addParticle(p);
}

LinkedCellContainer::LinkedCellContainer(std::array<int, 3> mesh_arg, double rcutoff_arg, std::vector<ParticleList>& list) {
    cells = list;
    mesh = mesh_arg;
    rcutoff = rcutoff_arg;

}

std::vector<ParticleList> LinkedCellContainer::getCells() const {
    return cells;
}

LinkedCellContainer::~LinkedCellContainer() = default;
