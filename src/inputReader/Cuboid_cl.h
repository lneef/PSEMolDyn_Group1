//
// Created by dominik on 05.11.22.
//

#pragma once

#include "../ParticleContainer.h"
#include "InputReader.h"
#include "CuboidGenerator.h"

namespace inputReader {
/**
 * @brief Cuboid_cl implements the interface provided by FileReader to perform queries from the command line
 *
 * TxtReader implements the abstract method provided by the class FileReader to perform queries from the command line regarding the values of cuboids and pass them to an instance of CuboidGenerator.
*/
    class Cuboid_cl : public InputReader {
    public:
        Cuboid_cl();

        ~Cuboid_cl() override;

        /**
         * @brief Performs queries from the command line regarding the values of cuboids and pass them to an instance of CuboidGenerator
         *
         * @param particles ParticleContainer where the particles are stored
        */
        void read(ParticleContainer &particles) override;
    };
}