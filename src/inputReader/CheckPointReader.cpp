
#include "CheckPointReader.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "MolSimLogger.h"

namespace inputReader {
    CheckPointReader::CheckPointReader(std::string filename) {
        this->filename = filename;
    }

    CheckPointReader::~CheckPointReader() = default;

    void CheckPointReader::read(std::shared_ptr<ParticleContainer>& particles) {
        std::array<double, 3> x{};
        std::array<double, 3> v{};
        std::array<double, 3> f{};
        std::array<double, 3> old_f{};
        double m;
        int type;
        double sigma;
        double epsilon;
        int num_particles = 0;

        std::ifstream input_file(filename.c_str());

        std::string tmp_string;

        if (input_file.is_open()) {

            getline(input_file, tmp_string);
            MolSimLogger::logDebug("Read line: {}", tmp_string);
            // std::cout << tmp_string << std::endl;
            getline(input_file, tmp_string);
            std::istringstream numstream(tmp_string);
            numstream >> num_particles;

            MolSimLogger::logInfo("Reading {} Particles.", num_particles);
            getline(input_file, tmp_string);
            MolSimLogger::logDebug("Read line: {}", tmp_string);

            for (int i = 0; i < num_particles; i++) {

                std::istringstream datastream(tmp_string);

                for (auto& xj : x) {
                    datastream >> xj;
                }
                for (auto& vj : v) {
                    datastream >> vj;
                }
                for (auto& fj : f) {
                    datastream >> fj;
                }
                for (auto& old_fj : old_f) {
                    datastream >> old_fj;
                }
                datastream >> m;
                datastream >> type;
                datastream >> sigma;
                datastream >> epsilon;
                if (datastream.eof()) {
                    MolSimLogger::logError("Error reading file: eof reached unexpectedly reading from line {}", i);
                    exit(-1);
                }
                Particle p(x, v, m, sigma, epsilon, type);
                p.setF(f);
                p.setOldF(old_f);



                particles->addParticle(p);



                getline(input_file, tmp_string);
                MolSimLogger::logDebug("Read line: {}", tmp_string);
            }
        }
        else {
            MolSimLogger::logError("Error: could not open file {}", filename);
            exit(-1);
        }
    }

    void CheckPointReader::read(std::shared_ptr<Simulation>& sim) {
        std::shared_ptr<ParticleContainer> particles = std::make_shared<ParticleContainer>();
        read(particles);
        sim->setParticle(particles);
    }
}
