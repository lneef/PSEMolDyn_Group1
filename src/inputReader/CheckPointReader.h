
#pragma once

#include "InputReader.h"
#include "Particle.h"
#include "FileReader.h"

namespace inputReader {
/**
 * @brief CheckPointReader implements the interface provided by FileReader for reading .txt files
 * 
 * CheckPointReader implements the abstract method provided by the class FileReader for reading particles from .txt files into an instance of ParticleContainer.
*/
    class CheckPointReader : public FileReader {

    public:
        explicit CheckPointReader(std::string filename);

        ~CheckPointReader() override;

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
