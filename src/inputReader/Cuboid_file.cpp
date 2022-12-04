//
// Created by dominik on 09.11.22.
//

#include "Cuboid_file.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "MolSimLogger.h"

namespace inputReader {
    Cuboid_file::Cuboid_file(std::string filename) {
        this->filename = filename;
    }

    Cuboid_file::~Cuboid_file() = default;

    //reads values from file
    void Cuboid_file::read(std::shared_ptr<ParticleContainer> &particles) {
        readCuboid(particles);
    }

    void Cuboid_file::read(std::shared_ptr<Simulation> &sim) {
        std::shared_ptr<ParticleContainer> particles = std::make_shared<ParticleContainer>();
        readCuboid(particles);
        sim->setParticle(particles);
    }
}