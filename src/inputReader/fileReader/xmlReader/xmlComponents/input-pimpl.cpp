//
// Created by dominik on 26.11.22.
//

#include "input-pimpl.h"
#include <iostream>

void input_pimpl::pre(std::vector<std::string> &input_path) {
    this->input_path=input_path;
}

void input_pimpl::path(const ::std::string &path) {
    input_path.push_back(path);
}

void input_pimpl::post_input() {}