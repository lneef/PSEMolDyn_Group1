//
// Created by lukas on 08.11.22.
//
#pragma once
#include <memory>
#include <iostream>

#include "ParticleContainer.h"
#include "outputWriter/FileWriter.h"
#include "forceCalculation/Force.h"


template<typename T1, typename T2>
class Simulation {
    ParticleContainer particles;
    const double start_time = 0.;
    double delta_t;
    double end_time;
    std::unique_ptr <outputWriter::FileWriter> writer;
    std::unique_ptr <Force> force;

public:
    void calculateX(){
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
    void calculateV(){
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
    void run() {
        std::string out_name("MD_vtk");

        double current_time = start_time;

        int iteration = 0;

        force -> calculateF(particles);

        while (current_time < end_time) {

            calculateX();

            force->calculateF(particles);

            calculateV();

            iteration++;
            if (iteration % 10 == 0) {
                writer->plotParticles(particles, out_name,iteration);
            }
            std::cout << "Iteration " << iteration << " finished." <<
                      std::endl;

            current_time +=delta_t;
        }
    }
    Simulation( ParticleContainer& particles, double delta_t, double end_time){
        this -> delta_t=delta_t;
        this -> end_time = end_time;
        this -> writer = std::make_unique<T1>();
        this -> force = std::make_unique<T2>();
        this -> particles.setParticles(particles.getParticles());


    }

};



