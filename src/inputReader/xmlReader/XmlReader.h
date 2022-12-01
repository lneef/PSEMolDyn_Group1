//
// Created by lukas on 01.12.22.
//
#pragma once

#include "inputReader/xmlReader/xmlpimpl/molecular_pimpl.h"

class XmlReader {

private:
    std::string filename;
    xml_schema::int_pimpl int_p;
    xml_schema::string_pimpl string_p;
    xml_schema::double_pimpl double_p;

    simulation_pimpl sim_p;
    cuboid_pimpl cub_p;
    cuboid_input_pimpl cub_in_p;
public:
    explicit XmlReader(std::string &s);
    void read(std::shared_ptr<Simulation> &sim);
    void read(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc);

};

