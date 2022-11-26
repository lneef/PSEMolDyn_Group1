//
// Created by dominik on 26.11.22.
//

#include "simulation-pimpl.h"
#include <iostream>

void simulation_pimpl::pre() {}

void simulation_pimpl::t_end(double t_end) {
    end_time = t_end;
}

void simulation_pimpl::delta_t(double delta_t) {
    delta_time = delta_t;
}

std::vector<double> simulation_pimpl::post_simulation() {
    std::vector<double> sim;
    sim.push_back(end_time);
    sim.push_back(delta_time);
    return sim;
}