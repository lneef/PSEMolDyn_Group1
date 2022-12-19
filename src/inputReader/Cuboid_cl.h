
#pragma once

#include "InputReader.h"
#include "ParticleGenerator.h"

namespace inputReader {
/**
 * @brief Cuboid_cl implements the interface provided by FileReader to perform queries from the command line
 *
 * TxtReader implements the abstract method provided by the class FileReader to perform queries from the command line regarding the values of cuboids and pass them to an instance of ParticleGenerator.
*/
    class Cuboid_cl : public InputReader {
    public:
        Cuboid_cl();

        ~Cuboid_cl() override;

        /**
         * @brief Performs queries from the command line regarding the values of cuboids and pass them to an instance of ParticleGenerator
         *
         * @param particles ParticleContainer where the particles are stored
        */
        void read(std::shared_ptr<ParticleContainer> &particles);

        /**
         * @brief overridden input function of InputReader
         * @param sim simulation that is initialized with the read input
         */
        void read(std::shared_ptr<Simulation> &sim) override;
    };
}