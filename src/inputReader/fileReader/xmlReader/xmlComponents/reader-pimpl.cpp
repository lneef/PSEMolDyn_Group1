//
// Created by dominik on 28.11.22.
//

#include "reader-pimpl.h"

void reader_pimpl::pre(std::string filename, std::unique_ptr<Force> &force,
                       std::unique_ptr<outputWriter::FileWriter> &writer,ParticleContainer &particles){
    this->filename = filename;
    this->force = std::move(force);
    this->writer = std::move(writer);
    this->part=std::move(particles);
}

void reader_pimpl::cuboid() {}

void reader_pimpl::simulation(std::vector<double> sim) {
    sim_values = sim;
}

void reader_pimpl::output(std::vector<std::string> out) {
    out_values=out;
}

void reader_pimpl::boundaries() {}

void reader_pimpl::input(std::string input_path) {
    in_values=input_path;
}

Simulation reader_pimpl::post_reader() {
    Simulation simulation(part, sim_values[1], sim_values[0], writer, force);
    simulation.setOut_name(out_values[0]);
    int frequency = stoi(out_values[1]);
    simulation.setOut_frequency(frequency);
}