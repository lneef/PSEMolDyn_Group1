//
// Created by dominik on 27.11.22.
//

#include "Cuboid_XMLFile.h"

namespace inputReader {
    Cuboid_XMLFile::Cuboid_XMLFile(std::string filename, std::unique_ptr<Force> force,
                                   std::unique_ptr<outputWriter::FileWriter> writer) {
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
        simulation_parser.t_end_parser(double_parser);
        simulation_parser.delta_t_parser(double_parser);

        boundaries_parser.pre();
        cuboid_parser.pre(particles);
        input_parser.pre();
        output_parser.pre();
        simulation_parser.pre();

        boundaries_parser.post_boundaries();
        cuboid_parser.post_cuboid();
        std::string input_path;
        input_path = input_parser.post_input();
        std::vector<std::string> out;
        out = output_parser.post_output();
        std::vector<double> sim;
        sim = simulation_parser.post_simulation();

        Simulation simulation(particles, sim[1], sim[0], writer, force);
        simulation.setOut_name(out[0]);
        int frequency = stoi(out[1]);
        simulation.setOut_frequency(frequency);
        simulation.run();
    }
}