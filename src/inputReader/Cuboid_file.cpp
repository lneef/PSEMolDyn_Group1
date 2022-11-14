//
// Created by dominik on 09.11.22.
//

#include "Cuboid_file.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../MolSimLogger.h"

namespace inputReader {
    Cuboid_file::Cuboid_file(char *filename) {
        this->filename = filename;
    }

    Cuboid_file::~Cuboid_file() = default;

    //reads values from file
    void Cuboid_file::read(ParticleContainer &particles) {
        std::array<double, 3> x;
        std::array<int, 3> n;
        double h;
        double m;
        std::array<double, 3> v;

        CuboidGenerator generator;

        int num_particles = 0;

        std::ifstream input_file(filename.c_str());
        std::string tmp_string;

        if (input_file.is_open()) {

            getline(input_file, tmp_string);
            MolSimLogger::logDebug("Read line: {}", tmp_string);

            while (tmp_string.empty() or tmp_string[0] == '#') {
                getline(input_file, tmp_string);
                MolSimLogger::logDebug("Read line: {}", tmp_string);
            }

            //read number of particles
            std::istringstream numstream(tmp_string);
            numstream >> num_particles;
            MolSimLogger::logInfo("Reading {} Particles.", num_particles);
            getline(input_file, tmp_string);
            MolSimLogger::logDebug("Read line: {}", tmp_string);


            //read actual values
            for (int i = 0; i < num_particles; i++) {
                std::istringstream datastream(tmp_string);

                for (auto &xj: x) {
                    datastream >> xj;
                }
                for (auto &nj: n) {
                    datastream >> nj;
                }
                datastream >> h;
                datastream >> m;
                for (auto &vj: v) {
                    datastream >> vj;
                }
                //passes values to CuboidGenerator

                generator.generateCuboid(particles, x, n, h, m, v);

                getline(input_file, tmp_string);
                MolSimLogger::logDebug("Read line: {}", tmp_string);
            }
        } else {
            MolSimLogger::logError("Error: could not open file {}", filename);
            exit(-1);
        }
    }
}