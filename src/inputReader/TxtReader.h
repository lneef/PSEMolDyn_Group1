
#pragma once

#include "InputReader.h"
#include "Particle.h"
#include "FileReader.h"

namespace inputReader {
/**
 * @brief TxtReader implements the interface provided by FileReader for reading .txt files
 * 
 * TxtReader implements the abstract method provided by the class FileReader for reading particles from .txt files into an instance of ParticleContainer.
*/
    class TxtReader : public FileReader {

    public:
        explicit TxtReader(std::string filename);

        ~TxtReader() override;

        /**
         * @brief Reads particles from input file and stores them in instance of ParticleContainer
         *
         * @param particles ParticleContainer where the particles are stored
        */
        void read(std::shared_ptr<ParticleContainer> &particles);

        /**
         * @brief implements read function of InputReader
         * @param sim object of type Simulation which is initialized while reading
         */
        void read(std::shared_ptr<Simulation> &sim) override;
    };
}
