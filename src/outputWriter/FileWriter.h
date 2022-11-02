#pragma once

#include<string>
#include "../ParticleContainer.h"

namespace outputWriter {
/**
 * 
 * @brief FileWriter provides a uniform interface for writing particles to an output file
*/
    class FileWriter {
    public:
        /**
         * @brief Writes particles from an instance of ParticleContainer to an output file
         *
         * @param particles ParticleContainer containg the particles to be plotted
         * @param filename filename specifies the name of the outputfile
         * @param iteration Number of the current iteration, used to generate the name of the output file
        */
        virtual void plotParticles(ParticleContainer &particles, const std::string &filename, int iteration) = 0;

        /**
         * @brief virtual destructor to prevent memory leaks
        */
        virtual ~FileWriter();
    };
}
