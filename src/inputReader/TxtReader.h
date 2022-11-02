/*
 * FileReader.h
 *
 *  Created on: 23.02.2010
 *      Author: eckhardw
 */

#pragma once

#include "../Particle.h"

#include "../ParticleContainer.h"

#include "FileReader.h"

namespace inputReader {
/**
 * @brief TxtReader implements the interface provided by FileReader for reading .txt files
 * 
 * TxtReader implements the abstract method provided by the class FileReader for reading particles from .txt files into an instance of ParticleContainer.
*/
    class TxtReader : public FileReader {

    public:
        TxtReader();

        virtual ~TxtReader();

        /**
         * @brief Reads particles from input file and stores them in instance of ParticleContainer
         *
         * @param particles ParticleContainer where the particles are stored
         * @param filename filename of the input file from where the particles are read
        */
        void readFile(ParticleContainer &particles, char *filename);
    };
}
