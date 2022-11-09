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

//ToDo: check correct input
        input:
        std::cout << "Specify coordinate of lower left front-side corner\n";
        std::cout << "Please enter x coordinate\n";
        std::cin >> x[0];
        std::cout << "Please enter y coordinate\n";
        std::cin >> x[1];
        std::cout << "Please enter z coordinate\n";
        std::cin >> x[2];

        std::cout << "Specify number of particles per dimension\n";
        std::cout << "Please enter number in x dimension\n";
        std::cin >> n[0];
        std::cout << "Please enter number in y dimension\n";
        std::cin >> n[1];
        std::cout << "Please enter number in z dimension\n";
        std::cin >> n[2];

        std::cout << "Specify distance between the particles\n";
        std::cout << "Please enter the distance\n";
        std::cin >> h;

        std::cout << "Specify mass of one particle\n";
        std::cout << "Please enter the mass\n";
        std::cin >> m;

        std::cout << "Specify velocity of the particles\n";
        std::cout << "Please enter velocity in x dimension\n";
        std::cin >> v[0];
        std::cout << "Please enter velocity in y dimension\n";
        std::cin >> v[1];
        std::cout << "Please enter velocity in z dimension\n";
        std::cin >> v[2];

        std::cout << "Specify mean velocity\n";
        std::cout << "Please enter velocity\n";
        std::cin >> mean_v;


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