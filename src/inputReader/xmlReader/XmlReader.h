//
// Created by lukas on 01.12.22.
//
#pragma once

#include "inputReader/xmlReader/xmlpimpl/molecular_pimpl.h"
#include "inputReader/FileReader.h"

namespace XMLReader {
    class XmlReader : public inputReader::FileReader {

    private:
        /**
         * @brief Filename of the xml-file
         */
        std::string filename;
        /**
         * @brief Parser of int
         */
        xml_schema::int_pimpl int_p;
        /**
         * @brief Parser of string
         */
        xml_schema::string_pimpl string_p;
        /**
         * @brief Parser of double
         */
        xml_schema::double_pimpl double_p;
        /**
         * @brief Parser of simulation
         */
        simulation_pimpl sim_p;
        /**
         * @brief Parser of cuboids
         */
        cuboid_pimpl cub_p;
        /**
         * @brief Parser of txt-file of cuboids
         */
        cuboid_input_pimpl cub_in_p;
        /**
         * @brief Parser of txt-file of spheres
         */
        spheres_input_pimpl sph_in_p;
        /**
         * @brief Parser of boundaries
         */
        boundaries_pimpl bou_in_p;

    public:
        /**
         * @brief Function that initializes the filename
         */
        explicit XmlReader(std::string &s);
        /**
         * @brief Function that reads the parameters of xml-file
         */
        void read(std::shared_ptr<Simulation> &sim) override;
        /**
         * @brief Function that generates a cell container and reads the parameters of xml-file
         */
        void read(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc);

    };

}