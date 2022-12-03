//
// Created by lukas on 01.12.22.
//
#pragma once

#include "inputReader/xmlReader/xmlpimpl/molecular_pimpl.h"
#include "inputReader/FileReader.h"

namespace XMLReader {
    class XmlReader : public inputReader::FileReader {

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

        void read(std::shared_ptr<Simulation> &sim) override;

        void read(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc);

    };

}