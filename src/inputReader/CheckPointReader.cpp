
#include "CheckPointReader.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "MolSimLogger.h"

namespace inputReader {
    CheckPointReader::CheckPointReader(std::string filename) {
        this->filename = filename;
    }

    CheckPointReader::~CheckPointReader() = default;

    void CheckPointReader::read(std::shared_ptr<ParticleContainer>& particles) {
        readInto(particles);
    }

    void CheckPointReader::read(std::shared_ptr<Simulation>& sim) {
        std::shared_ptr<ParticleContainer> particles = std::make_shared<ParticleContainer>();
        read(particles);
        sim->setParticle(particles);
    }
}
