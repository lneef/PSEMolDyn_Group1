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
        std::array<double, 3> n;
        double h;
        double m;
        std::array<double, 3> v;
        double mean_v;

        input:
        std::cout << "Specify the coordinate of lower left front-side corner\n";
        while(true) {
            std::cout << "Please enter x coordinate as double value\n";
            std::cin >> x[0];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for coordinates\n";
                continue;
            }
            break;
        }
        while(true) {
            std::cout << "Please enter y coordinate as double value\n";
            std::cin >> x[1];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for coordinates\n";
                continue;
            }
            break;
        }
        while(true) {
            std::cout << "Please enter z coordinate as double value\n";
            std::cin >> x[2];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for coordinates\n";
                continue;
            }
            break;
        }

        std::cout << "Specify the number of particles per dimension\n";
        while(true) {
            std::cout << "Please enter number in x dimension as double value\n";
            std::cin >> n[0];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for quantities\n";
                continue;
            }
            break;
        }
        while(true) {
            std::cout << "Please enter number in y dimension as double value\n";
            std::cin >> n[1];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for quantities\n";
                continue;
            }
            break;
        }
        while(true) {
            std::cout << "Please enter number in z dimension as double value\n";
            std::cin >> n[2];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for quantities\n";
                continue;
            }
            break;
        }

        std::cout << "Specify the distance between the particles\n";
        while(true) {
            std::cout << "Please enter the distance as double value\n";
            std::cin >> h;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for the distance\n";
                continue;
            }
            break;
        }

        std::cout << "Specify the mass of one particle\n";
        while(true) {
            std::cout << "Please enter the mass as double value\n";
            std::cin >> m;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for the mass\n";
                continue;
            }
            break;
        }


        std::cout << "Specify the velocity of the particles\n";
        while(true) {
            std::cout << "Please enter velocity in x dimension as double value\n";
            std::cin >> v[0];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for velocities\n";
                continue;
            }
            break;
        }
        while(true) {
            std::cout << "Please enter velocity in y dimension as double value\n";
            std::cin >> v[1];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for velocities\n";
                continue;
            }
            break;
        }
        while(true) {
            std::cout << "Please enter velocity in z dimension as double value\n";
            std::cin >> v[2];
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for velocities\n";
                continue;
            }
            break;
        }

        std::cout << "Specify the mean velocity\n";
        while(true) {
            std::cout << "Please enter the velocity as double value\n";
            std::cin >> mean_v;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please use a double value as input for velocities\n";
                continue;
            }
            break;
        }


        std::string more;
        std::cout << "Do you want to generate another cuboid of particles\n";

        //ToDo: Velocity calc; create particles

        selection:
        std::cout << "Yes or No\n";
        std::cin >> more;
        //ToDo: Warum funktioniert nicht mit compare()
        if (more == "yes" || more == "y" || more == "Yes" || more == "Y") {
            goto input;
        } else if ((more == "no" || more == "n" || more == "No" || more == "N")) {
            return;
        } else {
            std::cout << "Wrong input. Try again!\n";
            goto selection;
        }
    }
}