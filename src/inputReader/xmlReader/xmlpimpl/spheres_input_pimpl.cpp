//
// Created by dominik on 03.12.22.
//

#include "spheres_input_pimpl.h"
#include <iostream>

namespace XMLReader{
    void spheres_input_pimpl::init(std::shared_ptr<LinkedCellContainer> &cell_arg){
        cells=cell_arg;
    }
    void spheres_input_pimpl::path(const ::std::string &file) {
        path_spheres=file;
    }
    void spheres_input_pimpl::post_spheres_input() {
        inputReader::Cuboid_file spheres_reader(path_spheres);
        spheres_reader.readSphere(cells);
    }
}