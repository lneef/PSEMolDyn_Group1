//
// Created by dominik on 03.12.22.
//

#include "boundaries_impl.h"
#include <iostream>

namespace XMLReader {
    void boundaries_pimpl::top(const ::std::string &top) {
        std::cout << top << std::endl;
    }

    void boundaries_pimpl::bottom(const ::std::string &bottom) {
        std::cout << bottom << std::endl;
    }

    void boundaries_pimpl::left(const ::std::string &left) {
        std::cout << left << std::endl;
    }

    void boundaries_pimpl::right(const ::std::string &right) {
        std::cout << right << std::endl;
    }

    void boundaries_pimpl::post_boundaries() {

    }
}