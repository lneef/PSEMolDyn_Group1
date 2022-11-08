//
// Created by lukas on 08.11.22.
//
#pragma once
#include <memory>
#include <iostream>

#include "ParticleContainer.h"
#include "outputWriter/FileWriter.h"
#include "forceCalculation/Force.h"



class Simulation {
    ParticleContainer particles;
    const double start_time = 0.;
    double delta_t;
    double end_time;
    std::unique_ptr <outputWriter::FileWriter> writer;
    std::unique_ptr <Force> force;

public:
    void calculateX();
    void calculateV();
    void run();
    Simulation( ParticleContainer& particles, double delta_t, double end_time, std::unique_ptr <outputWriter::FileWriter>&& writer
    , std::unique_ptr <Force>&& force);

};



