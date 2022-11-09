//
// Created by lukas on 08.11.22.
//
#include "Simulation.h"

void Simulation::calculateX() {
    for (auto &p: particles) {
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempF{p.getF()};
        const std::array<double, 3> &tempX{p.getX()};

        std::array<double, 3> newX{};

        for (int i = 0; i < 3; i++)
            //Velocity-Störmer-Verlet-Algorithm
            newX[i] = tempX[i] + delta_t * tempV[i] + pow(delta_t, 2) * tempF[i] / (2 * p.getM());

        p.setX(newX);
    }
}

void Simulation::calculateV() {
    for (auto &p: particles) {
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempOldF{p.getOldF()};
        const std::array<double, 3> &tempF{p.getF()};

        std::array<double, 3> newV{};

        for (int i = 0; i < 3; i++) {
            //Velocity-Störmer-Verlet-Algorithm
            newV[i] = tempV[i] + delta_t * (tempOldF[i] + tempF[i]) / (2 * p.getM());
        }

        p.setV(newV);
    }
}

void Simulation::run() {
    std::string out_name("MD_vtk");

    double current_time = start_time;

    int iteration = 0;

    force->calculateF(particles);

    while (current_time < end_time) {

        calculateX();

        force->calculateF(particles);

        calculateV();

        iteration++;
        if (iteration % 10 == 0) {
            writer->plotParticles(particles, out_name, iteration);
        }
        std::cout << "Iteration " << iteration << " finished." <<
                  std::endl;

        current_time += delta_t;
    }
}

Simulation::Simulation(ParticleContainer &particles, double delta_t, double end_time,
                       std::unique_ptr<outputWriter::FileWriter> &&writer, std::unique_ptr<Force> &force) {
    this->delta_t = delta_t;
    this->end_time = end_time;
    this->writer = std::move(writer);
    this->force = std::move(force);
    this->particles.setParticles(particles.getParticles());

}