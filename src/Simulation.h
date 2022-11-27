//
// Created by lukas on 08.11.22.
//
#pragma once

#include <memory>
#include <iostream>

#include "ParticleContainer.h"
#include "outputWriter/FileWriter.h"
#include "forceCalculation/Force.h"
#include <chrono>

/**
 * @brief The class Simulation provides the functionality for running the simulation. It can be tailored to a specific
 * use case by initializing the fields accordingly
 */
class Simulation {
    /**
     * @brief ParticleContainer containing the particles for the simulation
     */
    ParticleContainer particles;
    /**
     * @brief start time of the simulation
     */
    const double start_time = 0.;

    /**
     * @brief time step after which values are updated
     */
    double delta_t;

    /**
     * @brief time at which the simulation ends
     */
    double end_time;

    /**
     * @brief FileWriter to print the VTK files
     */
    std::unique_ptr<outputWriter::FileWriter> writer;

    /**
     * @brief Force to calculate the force between particles
     */
    std::unique_ptr<Force> force;


    std::string out_name ="MD_vtk";
    int out_frequency = 10;

public:
    /**
     * @brief Calculats next position for each particle in particles
     */
    void calculateX();

    /**
     * @brief Calculates next velocity for each particle in particles
     */
    void calculateV();

    /**
     * @brief Function to start and run the simulation
     */
    void run();

    /**
     * @brief Constructor to initialize the simulation based on the use case.
     * @param particles ParticleContainer to store the involved particles
     * @param delta_t timestep for which the position, velocity and force is recalculated
     * @param end_time time at which the simulation ends
     * @param writer object to specify the output behaviour of the simualtion
     * @param force object to specify the type of force calculation used during the simulation
     */
    Simulation(ParticleContainer &particles, double delta_t, double end_time,
               std::unique_ptr<outputWriter::FileWriter> &writer, std::unique_ptr<Force> &force);

    void setOut_name(std::string &out_name);
    void setOut_frequency(int &out_frequency);
};



