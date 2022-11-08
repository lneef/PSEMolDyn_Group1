#include <getopt.h>
#include "inputReader/TxtReader.h"
#include "outputWriter/VTKWriter.h"
#include "utils/ArrayUtils.h"

#include <iostream>
#include <memory>

#include "forceCalculation/Gravitation.h"
#include "forceCalculation/Force.h"
#include "ParticleContainer.h"
#include "forceCalculation/LennardJones.h"
#include "inputReader/Cuboid_cl.h"

#include "Simulation.h"

constexpr double start_time = 0;
double end_time = 1000;
double delta_t = 0.014;

struct option long_option[]{
        {"help", no_argument, 0, 'a'},
        {0,0,0,0}
};


int main(int argc, char *argsv[]) {

    ParticleContainer particles{};
    std::unique_ptr<inputReader::FileReader> input;
    int optionindex;
    bool file_flag = 0;
    int arg = 0;
    while((arg = getopt_long(argc, argsv, "t:e:f:", long_option, &optionindex)) > 0){
        switch(arg){
            case 'a':
                break;
            case 't':
                delta_t = std::stod(optarg);
                break;
            case 'e':
                end_time = std::stod(optarg);
                break;
            case 'f':
                input = std::make_unique<inputReader::TxtReader>();
                input->readFile(particles, optarg);
                file_flag = 1;
                break;
            default:
                std::cout<<"Invalid command line argument" << arg << std::endl;
                exit(-1);

        }
    }
    if(!file_flag){
        inputReader::Cuboid_cl c{};
        c.readInput(particles);
    }

    Simulation simulation(particles, delta_t, end_time, std::make_unique<outputWriter::VTKWriter>(), std::make_unique<LennardJones>());
    simulation.run();

    std::cout << "output written. Terminating..." <<
              std::endl;
    return 0;
}

