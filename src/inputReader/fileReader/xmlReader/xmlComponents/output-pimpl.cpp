//
// Created by dominik on 26.11.22.
//

#include "output-pimpl.h"
#include <iostream>

void output_pimpl::pre(inputReader::Cuboid_XMLFile file) {
    this->file=file;
}

void output_pimpl::name(const ::std::string &name) {
    file.setOut_name(name);
}

void output_pimpl::frequency(int frequency) {
    file.setOut_frequency(frequency);
}

void output_pimpl::post_output() {}
