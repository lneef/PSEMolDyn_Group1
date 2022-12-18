
#pragma once

#include <fstream>
#include "InputReader.h"
#include "Particle.h"
#include "FileReader.h"
#include "MolSimLogger.h"

namespace inputReader {
/**
 * @brief CheckPointReader implements the interface provided by FileReader for reading .txt files
 * 
 * CheckPointReader implements the abstract method provided by the class FileReader for reading particles from .txt files into an instance of ParticleContainer.
*/
    class CheckPointReader : public FileReader {

    public:
        explicit CheckPointReader(std::string filename);

        ~CheckPointReader() override;

        /**
         * @brief Reads particles from input file and stores them in instance of ParticleContainer
         *
         * @param particles ParticleContainer where the particles are stored
        */
        void read(std::shared_ptr<ParticleContainer> &particles);

        /**
         * @brief implements read function of InputReader
         * @param sim object of type Simulation which is initialized while reading
         */
        void read(std::shared_ptr<Simulation> &sim) override;

        /**
         * @brief reads particles from a checkpoint file
         * @tparam T container class
         * @param particles reference to shared pointer to container class
         */
        template<class T> void readInto(std::shared_ptr<T> &particles){
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
    };
}
