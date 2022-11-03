#pragma once

#include<string>
#include "../ParticleContainer.h"

/**
 * @brief The namespace outputWriter contains the functionality to output particles to files
*/
namespace outputWriter {
/**
 * 
 * @brief FileWriter provides a uniform interface for writing particles to an output file
 * 
 * The class provides an abstract method plotParticles() which is implemented by its subclasses, This enables easier extensibility and integration of the methods for writing to files.
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
