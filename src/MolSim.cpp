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
        {"cub", optional_argument, 0, 'c'},
        {"planet", required_argument, 0 , 'p'},
        {0,0,0,0}
};
enum Option {None, Planet, Cuboid};
enum LogLevel{Log_0, Log_1, Log_2};

int main(int argc, char *argsv[]) {

    ParticleContainer particles{};
    std::unique_ptr<inputReader::InputReader> input;
    std::unique_ptr<Force> force;
    int8_t log_level = 0;
    int arg = 0;
    Option opt = None;
    while((arg = getopt_long(argc, argsv, "t:e:l:", long_option, 0)) != -1){
        switch(arg){
            case 'a':
                print_help();
                return 0;
            case 't':
                delta_t = std::stod(optarg);
                std::cout << "lol";
                break;
            case 'e':
                end_time = std::stod(optarg);
                break;
            case 'p':
                input = std::make_unique<inputReader::TxtReader>(optarg);
                force = std::make_unique<Gravitation>();
                opt = Planet;
                break;
            case 'c':
                if(optarg == NULL)
                    input = std::make_unique<inputReader::Cuboid_cl>();
                else

                force = std::make_unique<LennardJones>();
                opt = Cuboid;
                break;
            case 'l':
                //loglevel
                break;
            default:
                std::cout<<"Invalid command line argument" << arg << std::endl;
                exit(-1);

        }

    }
    if(opt == None){
        std::cout<<"You did not specify which simulation should be run"<< std::endl;
        exit(-1);
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

