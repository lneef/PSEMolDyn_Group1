//
// Created by dominik on 03.12.22.
//

#include "boundaries_impl.h"
#include "Reflecting.h"
#include "container/LinkedCellContainer.h"
#include <iostream>
#include "MolSimLogger.h"

namespace XMLReader {
    void boundaries_pimpl::top_boundary(const ::std::string &top) {
        MolSimLogger::logDebug("XMLReader: boundary {}", top);

        if (top == "reflecting"){
            cells->addReflecting(Reflecting(hor, cells->getDomain()[1]));
        }else if(top == "periodic"){
            periodic.emplace(3);
        }
    }

    void boundaries_pimpl::bottom_boundary(const ::std::string &bottom) {
        MolSimLogger::logDebug("XMLReader: boundary {}", bottom);

        if (bottom == "reflecting"){
            cells->addReflecting(Reflecting(hor, 0));
        }else if(bottom == "periodic"){
            periodic.emplace(1);
        }
    }

    void boundaries_pimpl::left_boundary(const ::std::string &left) {
        MolSimLogger::logDebug("XMLReader: boundary {}", left);

        if (left == "reflecting"){
            cells->addReflecting(Reflecting(vert, 0));
        } if(left == "periodic"){
            periodic.emplace(4);
        }
    }

    void boundaries_pimpl::right_boundary(const ::std::string &right) {
        MolSimLogger::logDebug("XMLReader: boundary {}", right);

        if (right == "reflecting"){
            cells->addReflecting(Reflecting(vert, cells->getDomain()[0]));
        } if(right == "periodic"){
            periodic.emplace(2);
        }
    }

    void boundaries_pimpl::post_boundaries() {
        if(periodic.contains(2) && periodic.contains(4))
            cells->addPeriodic(Boundary::VERTICAL);

        if(periodic.contains(3) && periodic.contains(1))
            cells->addPeriodic(Boundary::HORIZONTAL);
    }

    void boundaries_pimpl::init(std::shared_ptr<LinkedCellContainer> &cells_arg) {
        cells = cells_arg;
    }


}