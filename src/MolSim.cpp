#include <getopt.h>
#include "inputReader/TxtReader.h"
#include "inputReader/InputReader.h"
#include "outputWriter/VTKWriter.h"
#include <iostream>
#include <memory>
#include <map>

#include "forceCalculation/Gravitation.h"
#include "forceCalculation/Force.h"
#include "forceCalculation/LennardJones.h"
#include "inputReader/Cuboid_cl.h"
#include "inputReader/Cuboid_file.h"
#include "MolSimLogger.h"
#include "Simulation.h"
#include "inputReader/xmlReader/XmlReader.h"


void print_help();

constexpr double start_time = 0;
double end_time = 1000;
double delta_t = 0.014;


struct option long_option[]{
        {"help",   no_argument,       0, 'a'},
        {"cub",    optional_argument, 0, 'c'},
        {"planet", required_argument, 0, 'p'},
        {"xml",    required_argument, 0, 'x'},
        {0, 0,                        0, 0}
};

//map storing mapping argument -> lamda setting log level
std::map<std::string, std::function<void()>> levels{{"off",   []() { spdlog::set_level(spdlog::level::off); }},
                                                    {"info",  []() { spdlog::set_level(spdlog::level::info); }},
                                                    {"debug", []() { spdlog::set_level(spdlog::level::debug); }},
                                                    {"trace", []() { spdlog::set_level(spdlog::level::trace); }},
                                                    {"error", []() { spdlog::set_level(spdlog::level::err); }}};
enum Option {
    None, Planet, Cuboid, XMLCuboid
};

int main(int argc, char *argsv[]) {
    std::shared_ptr<ParticleContainer> particles = std::make_unique<ParticleContainer>();
    std::unique_ptr<inputReader::InputReader> input;
    std::shared_ptr<Simulation> simulation = std::make_shared<Simulation>();
    std::unique_ptr<Force> force;
    std::string filename;


    int arg = 0;
    bool arg_flag = false;
    Option opt = None;
    while ((arg = getopt_long(argc, argsv, "t:e:l:", long_option, nullptr)) != -1) {
        switch (arg) {
            case 'a':
                print_help();

                return 0;
            case 'x':
                filename = optarg;
                input = std::make_unique<XMLReader::XmlReader>(filename);
                arg_flag = true;
                opt = XMLCuboid;
                break;
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
    if (!arg_flag) {
        print_help();
        return 0;
    }
    if (opt == None) {
        std::cout << "You did not specify which simulation should be run" << std::endl;
        exit(-1);
    }

    MolSimLogger::init();
    std::unique_ptr<outputWriter::FileWriter> writer = std::make_unique<outputWriter::VTKWriter>();

    simulation->setWriter(writer);
    if (opt == Cuboid || opt == Planet) {
        simulation->setForce(force);
        simulation->setDeltaT(delta_t);
        simulation->setEndTime(end_time);
    }
    input->read(simulation);
    simulation->run();

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

