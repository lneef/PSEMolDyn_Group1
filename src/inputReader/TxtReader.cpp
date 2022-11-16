
#include "TxtReader.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../MolSimLogger.h"
namespace inputReader {
    TxtReader::TxtReader(char* filename) {
        this-> filename = filename;
    }

    TxtReader::~TxtReader() = default;

    void TxtReader::read(ParticleContainer &particles) {
        std::array<double, 3> x;
        std::array<double, 3> v;
        double m;
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

            std::istringstream numstream(tmp_string);
            numstream >> num_particles;
            MolSimLogger::logInfo("Reading {} Particles.", num_particles);
            getline(input_file, tmp_string);
            MolSimLogger::logDebug("Read line: {}", tmp_string);

            for (int i = 0; i < num_particles; i++) {
                std::istringstream datastream(tmp_string);

                for (auto &xj: x) {
                    datastream >> xj;
                }
                for (auto &vj: v) {
                    datastream >> vj;
                }
                if (datastream.eof()) {
                    MolSimLogger::logError("Error reading file: eof reached unexpectedly reading from line {}", i);
                    exit(-1);
                }
                datastream >> m;
                particles.addParticle(Particle(x, v, m));
                getline(input_file, tmp_string);
                MolSimLogger::logDebug("Read line: {}", tmp_string);
            }
        } else {
            MolSimLogger::logError("Error: could not open file {}", filename);
            exit(-1);
        }
    }
}
