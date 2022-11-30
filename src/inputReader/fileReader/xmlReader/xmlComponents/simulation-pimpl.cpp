//
// Created by dominik on 26.11.22.
//

#include "simulation-pimpl.h"
#include <iostream>

void simulation_pimpl::pre(std::shared_ptr<Simulation> &simulation, double &dom_size_ref, double &dom_cutOf_ref) {
    this->simulation = simulation;
    this->dom_size_ref = dom_size_ref;
    this->dom_cutOf_ref=dom_cutOf_ref;
}

void simulation_pimpl::t_end(double t_end) {
    end_time = t_end;
}

void simulation_pimpl::delta_t(double delta_t) {
    delta_time = delta_t;
}

void simulation_pimpl::domain_size(double dom_size) {
    dom_size_ref = dom_size;
}

void simulation_pimpl::domain_cutOf(double domain_cutOf) {
    dom_cutOf_ref = domain_cutOf;
}

void simulation_pimpl::post_simulation() {
    simulation->setEndTime(end_time);
    simulation->setDeltaT(delta_time);
}