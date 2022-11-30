//
// Created by dominik on 26.11.22.
//

#include "simulation-pimpl.h"
#include <iostream>

void simulation_pimpl::pre(inputReader::Cuboid_XMLFile file) {
    this->file = file;
}

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

void simulation_pimpl::post_simulation() {
    file.setT_end(end_time);
    file.setDelta_t(delta_time);
    file.setDom_size(dom_size);
    file.setDom_cutOf(dom_cutOf);
}