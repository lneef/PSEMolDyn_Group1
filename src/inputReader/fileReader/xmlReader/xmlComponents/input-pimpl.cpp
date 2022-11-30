//
// Created by dominik on 26.11.22.
//

#include "input-pimpl.h"
#include <iostream>

void input_pimpl::pre(inputReader::Cuboid_XMLFile file) {
    this->file = file;
}

void input_pimpl::path(const ::std::string &path) {
    input_path.push_back(path);
}

void input_pimpl::post_input() {
    file.setInput_path(input_path);
}