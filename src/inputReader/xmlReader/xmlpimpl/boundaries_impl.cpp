//
// Created by dominik on 03.12.22.
//

#include "boundaries_impl.h"
#include "Reflecting.h"
#include "container/LinkedCellContainer.h"
#include <iostream>

namespace XMLReader {
    void boundaries_pimpl::top(const ::std::string &top) {
        if (top == "reflecting")
            cells->addReflecting(Reflecting(hor, cells->getDomain()[1]));
    }

    void boundaries_pimpl::bottom(const ::std::string &bottom) {
        if (bottom == "reflecting")
            cells->addReflecting(Reflecting(hor, 0));
    }

    void boundaries_pimpl::left(const ::std::string &left) {
        std::cout<< "called";
        if (left == "reflecting")
            cells->addReflecting(Reflecting(hor, 0));
    }

    void boundaries_pimpl::right(const ::std::string &right) {
        if (right == "reflecting")
            cells->addReflecting(Reflecting(hor, cells->getDomain()[0]));
    }

    void boundaries_pimpl::post_boundaries() {
    }

    void boundaries_pimpl::init(std::shared_ptr<LinkedCellContainer> &cells_arg) {
        cells = cells_arg;
    }


}