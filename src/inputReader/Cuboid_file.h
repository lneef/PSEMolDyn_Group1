//
// Created by dominik on 09.11.22.
//

#pragma once

#include <fstream>
#include "inputReader/FileReader.h"
#include "CuboidGenerator.h"
#include "MolSimLogger.h"

namespace inputReader {
/**
 * @brief Cuboid_file implements the interface provided by FileReader for reading .txt files
 *
 * TxtReader implements the abstract method provided by the class FileReader for reading the values of cuboids from .txt files to pass them to an instance of CuboidGenerator.
*/
    class Cuboid_file : public FileReader {
    public:
        explicit Cuboid_file(std::string filename);

        ~Cuboid_file() override;

        /**
         * @brief Reads values of cuboids from input file and passes them to an instance of CuboidGenerator
         *
         * @param particles ParticleContainer where the particles are stored
        */
        void read(std::shared_ptr<ParticleContainer> &particles);

        void read(std::shared_ptr<Simulation> &sim) override;

        template<class T>
        void readCuboid(std::shared_ptr<T> &particles) {
            std::array<double, 3> x{};
            std::array<int, 3> n{};
            double h;
            double m;
            std::array<double, 3> v{};

            CuboidGenerator<T> generator;

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

                //read number of cuboids
                std::istringstream numstream(tmp_string);
                numstream >> num_particles;

                MolSimLogger::logInfo("Reading {} Cuboids.", num_particles);
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
                    MolSimLogger::logInfo("Cuboids generated!");

                    getline(input_file, tmp_string);
                    MolSimLogger::logDebug("Read line: {}", tmp_string);

                }
            } else {
                MolSimLogger::logError("Error: could not open file {}", filename);
                exit(-1);
            }
        }

        template<class T>
        void readSphere(std::shared_ptr<T> &particles) {
            std::array<double, 3> center{};
            int n;
            double h;
            double m;
            std::array<double, 3> v{};

            CuboidGenerator<T> generator;

            int num_spheres = 0;

            std::ifstream input_file(filename.c_str());
            std::string tmp_string;

            if (input_file.is_open()) {

                getline(input_file, tmp_string);
                MolSimLogger::logDebug("Read line: {}", tmp_string);

                while (tmp_string.empty() or tmp_string[0] == '#') {
                    getline(input_file, tmp_string);
                    MolSimLogger::logDebug("Read line: {}", tmp_string);
                }

                //read number of cuboids
                std::istringstream numstream(tmp_string);
                numstream >> num_spheres;

                MolSimLogger::logInfo("Reading {} spheres.", num_spheres);
                getline(input_file, tmp_string);
                MolSimLogger::logDebug("Read line: {}", tmp_string);
            }

            for (int i = 0; i < num_spheres; ++i) {
                std::istringstream data(tmp_string);

                for (auto &xi: center) {
                    data >> xi;
                }

                for (auto &vi: v) {
                    data >> vi;
                }

                data >> n;

                data >> h;

                data >> m;

                generator.generateSphere(particles, center, n, m, v, h);
                MolSimLogger::logInfo("Sphere generated!");
                getline(input_file, tmp_string);
            }
        }
    };
}