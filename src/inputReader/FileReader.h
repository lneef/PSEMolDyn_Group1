
#pragma once

#include "../ParticleContainer.h"
#include "Particle.h"

namespace inputReader {

/**
 * @brief FileReader provides a uniform interface for reading particles from a file
 * 
 * FileReader provides the abstract method readFile() which is implemented by its subclasses. This enables easier extension of the methods used to read from files and
 * a higher modularity by using the interface.
 * 
*/
    class FileReader {
    public:
        /**
         * @brief reads particles from file and stores them in an instance of ParticleContainer
         *
         * @param particles ParticleContainer where the read particles are stored.
         *
         * @param filename Name of the file from where particles are read
        */
        virtual void readFile(ParticleContainer &particles, char *filename) = 0;

        /**
         * @brief virtual destructor ro prevent memory leaks
        */
        virtual ~FileReader();
    };
}
