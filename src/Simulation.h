//
// Created by lukas on 08.11.22.
//
#pragma once

#include <memory>
#include <iostream>


#include "outputWriter/FileWriter.h"
#include "forceCalculation/Force.h"
#include "container/LinkedCellContainer.h"
#include <chrono>

/**
 * @brief The class Simulation provides the functionality for running the simulation. It can be tailored to a specific
 * use case by initializing the fields accordingly
 */
class Simulation {
    /**
     * @brief ParticleContainer containing the particles for the simulation
     */
    std::shared_ptr<Container>  particles;
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


    std::string out_name = "MD_vtk";
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
    Simulation(std::shared_ptr<Container>  &particles, double delta_t, double end_time,
               std::unique_ptr<outputWriter::FileWriter> &writer, std::unique_ptr<Force> &force);

    explicit Simulation(double delta_t_arg = 2, double end_time_arg = 0.0002);

    void setDeltaT(double delta_t_arg);
    void setEndTime(double end_time_arg);
    void setForce(std::unique_ptr<Force> &force_arg);

    void setParticle(std::shared_ptr<Container>  &particles_arg);
    void setParticle(std::shared_ptr<ParticleContainer>  &particles_arg);
    void setParticle(std::shared_ptr<LinkedCellContainer>  &particles_arg);

    void setOut_name(const std::string &out_name_arg);
    void setOut_frequency(int out_frequency_arg);

    void setWriter(std::unique_ptr<outputWriter::FileWriter> &writer_arg);

};



