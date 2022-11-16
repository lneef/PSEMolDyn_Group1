//
// Created by lukas on 08.11.22.
//
#include "Simulation.h"
#include "MolSimLogger.h"
#include "utils/ArrayUtils.h"

void Simulation::calculateX() {
    particles.apply([this](Particle &p) {
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempF{p.getF()};
        const std::array<double, 3> &tempX{p.getX()};

        std::array<double, 3> newX{};

        for (int i = 0; i < 3; i++)
            //Velocity-Störmer-Verlet-Algorithm
            newX[i] = tempX[i] + delta_t * tempV[i] + pow(delta_t, 2) * tempF[i] / (2 * p.getM());

        p.setX(newX);
    });
}

void Simulation::calculateV() {
    particles.apply([this](Particle &p) {
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempOldF{p.getOldF()};
        const std::array<double, 3> &tempF{p.getF()};

        std::array<double, 3> newV{};
        for (int i = 0; i < 3; i++) {
            //Velocity-Störmer-Verlet-Algorithm
            newV[i] = tempV[i] + delta_t * (tempOldF[i] + tempF[i]) / (2 * p.getM());
        }

        p.setV(newV);
    });
}

void Simulation::run() {
    std::string out_name("MD_vtk");

    auto start = std::chrono::high_resolution_clock::now();

    double current_time = start_time;

    int iteration = 0;

    force->calculateF(particles);

    while (current_time < end_time) {

        calculateX();
        SPDLOG_LOGGER_INFO(MolSimLogger::logger(), "Position of particles calculated for iteration {} ", iteration);

        force->calculateF(particles);
        SPDLOG_LOGGER_INFO(MolSimLogger::logger(), "Force on particles calculated for iteration {}", iteration);

        calculateV();
        SPDLOG_LOGGER_INFO(MolSimLogger::logger(), "Velocities of particles calculated for iteration {}", iteration);

        iteration++;
#ifndef BENCHMARK
        if (iteration % 10 == 0) {
            writer->plotParticles(particles, out_name, iteration);
        }
#endif
        SPDLOG_LOGGER_INFO(MolSimLogger::logger(), "Itertation {} finished. ", iteration);

        current_time += delta_t;
    }


    auto stop = std::chrono::high_resolution_clock::now();
    auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << difference.count() << "ms" << std::endl;
}

Simulation::Simulation(ParticleContainer &particles, double delta_t, double end_time,
                       std::unique_ptr<outputWriter::FileWriter> &writer, std::unique_ptr<Force> &force) {
    this->delta_t = delta_t;
    this->end_time = end_time;
    this->writer = std::move(writer);
    this->force = std::move(force);
    this->particles.setParticles(particles.getParticles());

}