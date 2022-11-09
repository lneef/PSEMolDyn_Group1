#include <getopt.h>
#include "inputReader/TxtReader.h"
#include "outputWriter/VTKWriter.h"
#include "inputReader/InputReader.h"

#include <iostream>
#include <memory>

#include "forceCalculation/Gravitation.h"
#include "forceCalculation/Force.h"
#include "ParticleContainer.h"
#include "forceCalculation/LennardJones.h"
#include "inputReader/Cuboid_cl.h"

#include "Simulation.h"


void print_help();

constexpr double start_time = 0;
double end_time = 1000;
double delta_t = 0.014;

struct option long_option[]{
        {"help", no_argument, 0, 'a'},
        {"file", required_argument, 0, 'f'},
        {0,0,0,0}
};
enum Option {Planet, Cuboid};

int main(int argc, char *argsv[]) {

    ParticleContainer particles{};
    std::unique_ptr<inputReader::InputReader> input;
    std::unique_ptr<Force> force = std::make_unique<Gravitation>();
    bool changed = false;
    bool file_flag = false;
    int arg = 0;
    Option opt = Cuboid;

    while((arg = getopt_long(argc, argsv, "t:e:", long_option, 0)) != -1){
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
                input = std::make_unique<inputReader::TxtReader>(optarg);
                std::cout<< optarg << std::endl;
                file_flag = true;
                break;
            default:
                std::cout<<"Invalid command line argument" << arg << std::endl;
                exit(-1);

        }

        if(!file_flag){
            input = std::make_unique<inputReader::Cuboid_cl>();
        }
    }

    input->read(particles);
    Simulation simulation(particles, delta_t, end_time, std::make_unique<outputWriter::VTKWriter>(), force);
    simulation.run();

    std::cout << "output written. Terminating..." <<
              std::endl;
    return 0;
}

void print_help(){

}

