//
// Created by lukas on 01.12.22.
//

#include <iostream>
#include "cuboid_input_pimpl.h"

namespace XMLReader {
    void cuboid_input_pimpl::init(std::shared_ptr<LinkedCellContainer> &cell_arg){
        cells = cell_arg;
    }
    void cuboid_input_pimpl::path(const std::string &file) {
        path_cuboids=file;
    }

    void cuboid_input_pimpl::post_cuboid_input() {
        inputReader::Cuboid_file cuboids_reader(path_cuboids);
        cuboids_reader.readCuboid(cells);
    }
}