//
// Created by dominik on 09.11.22.
//

#include "Cuboid_file.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

namespace inputReader {
    Cuboid_file::Cuboid_file(char *filename) {
        this->filename = filename;
    }

    Cuboid_file::~Cuboid_file() = default;

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
            std::cout << "Read line: " << tmp_string << std::endl;

            while (tmp_string.empty() or tmp_string[0] == '#') {
                getline(input_file, tmp_string);
                std::cout << "Read line: " << tmp_string << std::endl;
            }

            std::istringstream numstream(tmp_string);
            numstream >> num_particles;
            std::cout << "Reading " << num_particles << "." << std::endl;
            getline(input_file, tmp_string);
            std::cout << "Read line: " << tmp_string << std::endl;

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
                generator.generateCuboid(particles,x,n,h,m,v);

                getline(input_file, tmp_string);
                std::cout << "Read line: " << tmp_string << std::endl;
            }
        } else {
            std::cout << "Error: could not open file " << filename << std::endl;
            exit(-1);
        }
    }
}