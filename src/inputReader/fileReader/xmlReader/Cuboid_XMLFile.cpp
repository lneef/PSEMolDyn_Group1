//
// Created by dominik on 27.11.22.
//

#include "Cuboid_XMLFile.h"

namespace inputReader {
    Cuboid_XMLFile::Cuboid_XMLFile(std::string filename, std::unique_ptr<Force> &force,
                                   std::unique_ptr<outputWriter::FileWriter> &writer,
                                   std::shared_ptr<Simulation> &sim) {
        this->filename = filename;
        this->force = std::move(force);
        this->writer = std::move(writer);
        this->simulation = sim;
    }

    Cuboid_XMLFile::~Cuboid_XMLFile() = default;

    void Cuboid_XMLFile::read(std::unique_ptr<Container> &particles) {
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
        cuboid_parser.pre(this);
        input_parser.pre(this);
        output_parser.pre(this);
        simulation_parser.pre(this);
        reader_parser.pre(this);

        doc.parse("cuboid.xml");
        reader_parser.post_reader();

        simulation->setEndTime(t_end);
        simulation->setDeltaT(delta_t);
        simulation->setWriter(writer);
        simulation->setForce(force);
        simulation->setOut_name(out_name);
        simulation->setOut_frequency(out_frequency);

        CuboidGenerator<Container> generator;
        for (int i = 0; i < positions.size(); i++) {
            generator.generateCuboid(particles, positions[i], quantities[i], distances[i], masses[i], velocities[i]);
        }

    }

    void Cuboid_XMLFile::setInput_path(std::vector<std::string> in_path) {
        for (auto &path: in_path) {
            input_path.push_back(path);
        }
    }

    void Cuboid_XMLFile::setT_end(double t_end) {
        this->t_end = t_end;
    }

    void Cuboid_XMLFile::setDelta_t(double delta_t) {
        this->delta_t = delta_t;
    }

    void Cuboid_XMLFile::setDom_size(double dom_size) {
        this->dom_size = dom_size;
    }

    void Cuboid_XMLFile::setDom_cutOf(double dom_cutOf) {
        this->dom_cutOf = dom_cutOf;
    }

    void Cuboid_XMLFile::setOut_Name(std::string out_name) {
        this->out_name = out_name;
    }

    void Cuboid_XMLFile::setOut_frequency(int out_frequency) {
        this->out_frequency = out_frequency;
    }

    void Cuboid_XMLFile::setPostitions(std::array<double, 3> positions) {
        this->positions.push_back(positions);
    }

    void Cuboid_XMLFile::setQuantities(std::array<int, 3> quantities) {
        this->quantities.push_back(quantities);
    }

    void Cuboid_XMLFile::setDistances(double distances) {
        this->distances.push_back(distances);
    }

    void Cuboid_XMLFile::setMasses(double masses) {
        this->masses.push_back(masses);
    }

    void Cuboid_XMLFile::setVelocities(std::array<double, 3> velocities) {
        this->velocities.push_back(velocities);
    }
}
