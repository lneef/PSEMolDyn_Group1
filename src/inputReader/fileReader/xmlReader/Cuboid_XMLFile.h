//
// Created by dominik on 27.11.22.
//
#pragma once

#include "xmlComponents/boundaries-pimpl.h"
#include "xmlComponents/cuboid-pimpl.h"
#include "xmlComponents/input-pimpl.h"
#include "xmlComponents/output-pimpl.h"
#include "xmlComponents/simulation-pimpl.h"
#include "xmlComponents/reader-pimpl.h"
#include "../../../Simulation.h"
#include "../FileReader.h"
#include "../../CuboidGenerator.h"

namespace inputReader {
    class Cuboid_XMLFile{
    protected:
        boundaries_pimpl boundaries_parser;
        cuboid_pimpl cuboid_parser;
        input_pimpl input_parser;
        output_pimpl output_parser;
        simulation_pimpl simulation_parser;
        reader_pimpl reader_parser;
        xml_schema::double_pimpl double_parser;
        xml_schema::integer_pimpl integer_parser;
        xml_schema::string_pimpl string_parser;
        std::unique_ptr<Force> force;
        std::unique_ptr<outputWriter::FileWriter> writer;
        std::shared_ptr<Simulation> simulation;
        std::string filename;


        //input
        std::vector<std::string> input_path;

        //output
        std::string out_name;
        int out_frequency;

        //simulation
        double t_end;
        double delta_t;
        double dom_size;
        double dom_cutOf;

        //cuboid
        std::vector<std::array<double,3>> positions;
        std::vector<std::array<int,3>> quantities;
        std::vector<double> distances;
        std::vector<double> masses;
        std::vector<std::array<double, 3>> velocities;

    public:
        explicit Cuboid_XMLFile(std::string filename, std::unique_ptr<Force> &force,
                                std::unique_ptr<outputWriter::FileWriter> &writer, std::shared_ptr<Simulation> &sim);

        ~Cuboid_XMLFile();

        void read(std::unique_ptr<Container> &particles);

        void setInput_path(std::vector<std::string> in_path);
        void setT_end(double t_end);
        void setDelta_t(double delta_t);
        void setDom_size(double dom_size);
        void setDom_cutOf(double dom_cutOf);
        void setOut_Name(std::string out_name);
        void setOut_frequency(int out_frequency);
        void setPostitions(std::array<double,3> positions);
        void setQuantities(std::array<int,3> quantities);
        void setDistances(double distances);
        void setMasses(double masses);
        void setVelocities(std::array<double, 3> velocities);
    };
}
