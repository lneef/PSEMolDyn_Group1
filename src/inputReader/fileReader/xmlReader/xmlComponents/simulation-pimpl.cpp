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

void simulation_pimpl::domain_size(double domain_size) {
    dom_size = domain_size;
}

void simulation_pimpl::domain_cutOf(double domain_cutOf) {
    dom_cutOf = domain_cutOf;
}

std::vector<double> simulation_pimpl::post_simulation() {
    std::vector<double> sim;
    sim.push_back(end_time);
    sim.push_back(delta_time);
    sim.push_back(dom_size);
    sim.push_back(dom_cutOf);
    return sim;
}