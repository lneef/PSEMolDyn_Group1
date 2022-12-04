//
// Created by dominik on 03.12.22.
//

#pragma once

#include "inputReader/xmlReader/molsim-pskel.h"
#include "container/LinkedCellContainer.h"
#include "../../Cuboid_file.h"

namespace XMLReader {
    class spheres_input_pimpl : public spheres_input_pskel {
    private:
        std::shared_ptr<LinkedCellContainer> cells;
        std::string path_spheres;
    public:
        void init(std::shared_ptr<LinkedCellContainer> &cell_arg);

        void path(const ::std::string &) override;

        void post_spheres_input() override;
    };
}