//
// Created by dominik on 26.11.22.
//

#include "input-pimpl.h"
#include <iostream>

void input_pimpl::pre() {}

void input_pimpl::path(const ::std::string &path) {
    input_path = path;
}

std::string input_pimpl::post_input() {
    return input_path;
}