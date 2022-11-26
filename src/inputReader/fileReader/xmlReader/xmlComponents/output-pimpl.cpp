//
// Created by dominik on 26.11.22.
//

#include "output-pimpl.h"
#include <iostream>

void output_pimpl::pre() {}

void output_pimpl::name(const ::std::string &name) {
    out_name = name;
}

void output_pimpl::frequency(double frequency) {
    out_frequency = frequency;
}

std::vector<std::string> output_pimpl::post_output() {
    std::vector<std::string> out;
    out.push_back(out_name);
    out.push_back(out_frequency);
    return out;
}
