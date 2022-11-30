//
// Created by dominik on 26.11.22.
//

#include "output-pimpl.h"
#include <iostream>

void output_pimpl::pre(inputReader::Cuboid_XMLFile file) {
    this->file=file;
}

void output_pimpl::name(const ::std::string &name) {
    out_name = name;
}

void output_pimpl::frequency(int frequency) {
    out_frequency = frequency;
}

void output_pimpl::post_output() {}
