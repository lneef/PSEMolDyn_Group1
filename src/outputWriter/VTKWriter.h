/*
 * VTKWriter.h
 *
 *  Created on: 01.03.2010
 *      Author: eckhardw
 */

#pragma once

#include "Particle.h"
#include "outputWriter/vtk-unstructured.h"
#include "FileWriter.h"
#include "../ParticleContainer.h"

namespace outputWriter {

/**
 * This class implements the functionality to generate vtk output from
 * particles. It implements the interface provided by FileWriter. 
 */
    class VTKWriter : public FileWriter {

    public:
        VTKWriter();

        virtual ~VTKWriter();

        /**
         * set up internal data structures and prepare to plot a particle.
         */
        void initializeOutput(int numParticles);

        /**
         * plot type, mass, position, velocity and force of a particle.
         *
         * @note: initializeOutput() must have been called before.
         */
        void plotParticle(Particle &p);

        /**
         * writes the final output file.
         *
         * @param filename the base name of the file to be written.
         * @param iteration the number of the current iteration,
         *        which is used to generate an unique filename
         */
        void writeFile(const std::string &filename, int iteration);

        /**
         * This function:
         *  1. initializes the internal data structure via initializeOutput()
         *  2. plots all passed particles via plotParticle()
         *  3. writes final output to an output file via writeFile()
         *
         * Particles are written using the VTK-format.
         *
         * @param particles ParticleContainer containing the particles to be plotted
         * @param filename string specifing output file
         * @param iteration Number of th current iteration, used to generate the name of the output file
         */
        void plotParticles(ParticleContainer &particles, const std::string &filename, int iteration) override;

    private:
        VTKFile_t *vtkFile;
    };

} // namespace outputWriter
