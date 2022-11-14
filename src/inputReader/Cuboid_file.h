//
// Created by dominik on 09.11.22.
//

#pragma once

#include "FileReader.h"
#include "CuboidGenerator.h"

namespace inputReader {
/**
 * @brief Cuboid_file implements the interface provided by FileReader for reading .txt files
 *
 * TxtReader implements the abstract method provided by the class FileReader for reading the values of cuboids from .txt files to pass them to an instance of CuboidGenerator.
*/
    class Cuboid_file : public FileReader {
    public:
        explicit Cuboid_file(char *filename);

        ~Cuboid_file() override;

        /**
         * @brief Reads values of cuboids from input file and passes them to an instance of CuboidGenerator
         *
         * @param particles ParticleContainer where the particles are stored
         * @param filename filename of the input file from where the values are read
        */
        void read(ParticleContainer &particles) override;
    };
}