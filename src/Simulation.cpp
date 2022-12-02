//
// Created by lukas on 08.11.22.
//
#include "Simulation.h"
#include "MolSimLogger.h"
#include "utils/ArrayUtils.h"

void Simulation::calculateX() {
    particles->applyX([this](Particle &p) {
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
    particles->apply([this](Particle &p) {
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
    //flush logger in benchmark mode
#ifdef BENCHMARK
    MolSimLogger::logger()->flush();
#endif

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
        if (iteration % out_frequency == 0) {
            writer->plotParticles(particles, out_name, iteration);
        }

        MolSimLogger::logInfo("Itertation {} finished. ", iteration);
#endif
        current_time += delta_t;
    }


    auto stop = std::chrono::high_resolution_clock::now();
    auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << difference.count() << "ms" << std::endl;
}

Simulation::Simulation(std::shared_ptr<Container> &particles, double delta_t, double end_time,
                       std::unique_ptr<outputWriter::FileWriter> &writer, std::unique_ptr<Force> &force) {
    this->delta_t = delta_t;
    this->end_time = end_time;
    this->writer = std::move(writer);
    this->force = std::move(force);
    this->particles = std::move(particles);

}

void Simulation::setDeltaT(double delta_t_arg) {
    delta_t = delta_t_arg;
}

void Simulation::setEndTime(double end_time_arg) {
    end_time = end_time_arg;
}

void Simulation::setParticle(std::shared_ptr<Container> &particles_arg) {
    particles = std::move(particles_arg);
}

void Simulation::setParticle(std::shared_ptr<ParticleContainer> &particles_arg) {
    particles = std::move(particles_arg);
}

void Simulation::setParticle(std::shared_ptr<LinkedCellContainer> &particles_arg) {
    particles = std::move(particles_arg);
}

Simulation::Simulation(double delta_t_arg, double end_time_arg) {
    delta_t = delta_t_arg;
    end_time = end_time_arg;
}

void Simulation::setForce(std::unique_ptr<Force> &force_arg) {
    force = std::move(force_arg);
}

void Simulation::setOut_frequency(int out_frequency_arg) {
    out_frequency = out_frequency_arg;
}

void Simulation::setWriter(std::unique_ptr<outputWriter::FileWriter> &writer_arg) {
    writer = std::move(writer_arg);
}

void Simulation::setOut_name(const std::string &out_name_arg) {
    out_name = out_name_arg;

}

