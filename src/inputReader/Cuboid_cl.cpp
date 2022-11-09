//
// Created by dominik on 05.11.22.
//
#include "Cuboid_cl.h"
#include <iostream>

namespace inputReader {
    Cuboid_cl::Cuboid_cl() = default;

    Cuboid_cl::~Cuboid_cl() = default;

    void Cuboid_cl::read(ParticleContainer &particles) {
        std::array<double, 3> x;
        std::array<int, 3> n;
        double h;
        double m;
        std::array<double, 3> v;

        CuboidGenerator cuboidGenerator;

        int num_particles;
        std::cout << "How many cuboids you want to generate?\n";
        while (true) {
            std::cout << "Please enter a number as integer greater than or equal to 1\n";
            std::cin >> num_particles;
            if (std::cin.fail() || num_particles < 0) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use an integer greater than or equal to 1\n";
                continue;
            }
            break;
        }

        for (int i = 0; i < num_particles; i++) {
            std::cout << "Specify the coordinate of lower left front-side corner\n";
            while (true) {
                std::cout << "Please enter x coordinate as double value\n";
                std::cin >> x[0];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for coordinates\n";
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Please enter y coordinate as double value\n";
                std::cin >> x[1];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for coordinates\n";
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Please enter z coordinate as double value\n";
                std::cin >> x[2];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for coordinates\n";
                    continue;
                }
                break;
            }

            std::cout << "Specify the number of particles per dimension\n";
            while (true) {
                std::cout << "Please enter the quantity in x dimension as an integer\n";
                std::cin >> n[0];
                if (std::cin.fail() || n[0] < 0) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a integer greater than 0 as input for quantities\n";
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Please enter the quantity in y dimension as an integer\n";
                std::cin >> n[1];
                if (std::cin.fail() || n[0] < 0) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a nteger greater than 0 as input for quantities\n";
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Please enter the quantity in z dimension as an integer\n";
                std::cin >> n[2];
                if (std::cin.fail() || n[0] < 0) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a nteger greater than 0 as input for quantities\n";
                    continue;
                }
                break;
            }

            std::cout << "Specify the distance between the particles\n";
            while (true) {
                std::cout << "Please enter the distance as double value\n";
                std::cin >> h;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for the distance\n";
                    continue;
                }
                break;
            }

            std::cout << "Specify the mass of one particle\n";
            while (true) {
                std::cout << "Please enter the mass as double value\n";
                std::cin >> m;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for the mass\n";
                    continue;
                }
                break;
            }


            std::cout << "Specify the velocity of the particles\n";
            while (true) {
                std::cout << "Please enter velocity in x dimension as double value\n";
                std::cin >> v[0];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for velocities\n";
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Please enter velocity in y dimension as double value\n";
                std::cin >> v[1];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for velocities\n";
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Please enter velocity in z dimension as double value\n";
                std::cin >> v[2];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please use a double value as input for velocities\n";
                    continue;
                }
                break;
            }
            cuboidGenerator.generateCuboid(particles, x, n, h, m, v);
        }
    }
}