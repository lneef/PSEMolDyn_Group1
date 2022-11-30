//
// Created by dominik on 26.11.22.
//

#include "output-pimpl.h"
#include <iostream>

void output_pimpl::pre(std::shared_ptr<Simulation> &simulation) {
    this->simulation = simulation;
}

void output_pimpl::name(const ::std::string &name) {
    simulation->setOut_name(const_cast<std::string &>(name));
}

void output_pimpl::frequency(int frequency) {
    simulation->setOut_frequency(frequency);
}

void output_pimpl::post_output() {}
