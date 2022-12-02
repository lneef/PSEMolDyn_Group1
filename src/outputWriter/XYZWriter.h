/*
 * XYZWriter.h
 *
 *  Created on: 01.03.2010
 *      Author: eckhardw
 */

#pragma once

#include "../Particle.h"
#include "FileWriter.h"
#include <fstream>


namespace outputWriter {

/**
 * @brief XYZWriter implements the interface provided by FileWriter
 * 
*/
    class XYZWriter : public FileWriter {

    public:
        XYZWriter();

        virtual ~XYZWriter();

        /**
         * @brief Writes particles from instance of ParticleContainer to an output file using the XYZ-format
         *
         * @param particles ParticleContainer containing the particles to be plotted
         * @param filename filename specifies the name of the output file
         * @param iteration Number of the current iteration, used to generate the name of the output fule
         *
        */
        void plotParticles(std::shared_ptr<Container> &particles, const std::string &filename, int iteration) override;
    };

} // namespace outputWriter
