//
// Created by dominik on 27.11.22.
//

#include "Cuboid_XMLFile.h"

namespace inputReader {
    Cuboid_XMLFile::Cuboid_XMLFile(std::string filename, std::unique_ptr<Force> &force,
                                   std::unique_ptr<outputWriter::FileWriter> &writer, Simulation &sim) : simulation(
            sim) {
        this->filename = filename;
        this->force = std::move(force);
        this->writer = std::move(writer);
    }

    Cuboid_XMLFile::~Cuboid_XMLFile() = default;

    void Cuboid_XMLFile::read(ParticleContainer &particles) {
        cuboid_parser.x_parser(double_parser);
        cuboid_parser.n_parser(int_parser);
        cuboid_parser.h_parser(double_parser);
        cuboid_parser.m_parser(double_parser);
        cuboid_parser.v_parser(double_parser);
        input_parser.path_parser(string_parser);
        output_parser.frequency_parser(double_parser);
        output_parser.name_parser(string_parser);
        simulation_parser.t_end_parser(double_parser);
        simulation_parser.delta_t_parser(double_parser);
        reader_parser.cuboid_parser(cuboid_parser);
        reader_parser.simulation_parser(simulation_parser);
        reader_parser.output_parser(output_parser);
        reader_parser.boundaries_parser(boundaries_parser);
        reader_parser.input_parser(input_parser);

        xml_schema::document doc(reader_parser, "cuboid");

        boundaries_parser.pre();
        cuboid_parser.pre(particles);
        input_parser.pre();
        output_parser.pre();
        simulation_parser.pre();
        reader_parser.pre(filename, force, writer, particles);

        doc.parse("cuboid.xml");

        simulation = reader_parser.post_reader();
    }
}
