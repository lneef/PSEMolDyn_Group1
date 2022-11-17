#include <getopt.h>
#include "inputReader/TxtReader.h"
#include "outputWriter/VTKWriter.h"
#include "inputReader/InputReader.h"

#include <iostream>
#include <memory>
#include <fstream>
#include <map>

#include "forceCalculation/Gravitation.h"
#include "forceCalculation/Force.h"
#include "ParticleContainer.h"
#include "forceCalculation/LennardJones.h"
#include "inputReader/Cuboid_cl.h"
#include "inputReader/Cuboid_file.h"
#include "MolSimLogger.h"
#include "Simulation.h"


void print_help();
int p[1] = {0};
constexpr double start_time = 0;
double end_time = 1000;
double delta_t = 0.014;


struct option long_option[]{
        {"help",   no_argument,       0, 'a'},
        {"cub",    optional_argument, 0, 'c'},
        {"planet", required_argument, 0, 'p'},
        {0, 0,                        0, 0}
};

//map storing mapping argument -> lamda setting log level
std::map<std::string, std::function<void()>> levels{{"off", []() { spdlog::set_level(spdlog::level::off); }},
                                                    {"info", []() { spdlog::set_level(spdlog::level::info); }},
                                                    {"debug", []() { spdlog::set_level(spdlog::level::debug); }},
                                                    {"trace", []() { spdlog::set_level(spdlog::level::trace); }},
                                                    {"error", []() { spdlog::set_level(spdlog::level::err); }}};
enum Option {
    None, Planet, Cuboid
};

int main(int argc, char *argsv[]) {

    ParticleContainer particles{};
    std::unique_ptr<inputReader::InputReader> input;
    std::unique_ptr<Force> force;
    MolSimLogger::init();
    int arg = 0;
    bool arg_flag = false;
    Option opt = None;
    while ((arg = getopt_long(argc, argsv, "t:e:l:", long_option, nullptr)) != -1) {
        switch (arg) {
            case 'a':
                print_help();

                return p[1];
            case 't':
                delta_t = std::stod(optarg);
                arg_flag = true;
                break;
            case 'e':
                end_time = std::stod(optarg);
                arg_flag = true;
                break;
            case 'p':
                //planet simulation
                input = std::make_unique<inputReader::TxtReader>(optarg);
                force = std::make_unique<Gravitation>();
                opt = Planet;
                arg_flag = true;
                break;
            case 'c':
                //cuboid simulation
                if (optarg == nullptr) {
                    input = std::make_unique<inputReader::Cuboid_cl>();
                } else {
                    input = std::make_unique<inputReader::Cuboid_file>(optarg);
                }
                force = std::make_unique<LennardJones>();
                opt = Cuboid;
                arg_flag = true;
                break;
            case 'l':
                if (!levels.contains(optarg)) {
                    exit(-1);
                }
                levels[optarg]();
                arg_flag = true;
                break;
            default:
                std::cout << "Invalid command line argument" << arg << std::endl;
                exit(-1);

        }

    }
    if(!arg_flag){
        print_help();
        return 0;
    }
    if (opt == None) {
        std::cout << "You did not specify which simulation should be run" << std::endl;
        exit(-1);
    }
    input->read(particles);
    std::unique_ptr<outputWriter::FileWriter> writer = std::make_unique<outputWriter::VTKWriter>();
    Simulation simulation(particles, delta_t, end_time, writer, force);
    simulation.run();

    MolSimLogger::logInfo("Output written. Terminating...");
    return 0;
}

void print_help() {
    //read help page from file
    std::ifstream file("../input/man.txt");
    std::string tmp;
    if (!file.is_open()) {
        MolSimLogger::logError("Reading from man.txt failed!");
        exit(-1);
    }
    while (!file.eof()) {
        getline(file, tmp);
        std::cout << tmp << std::endl;
    }

    MolSimLogger::logDebug("Manpage printed");
}

