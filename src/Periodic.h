//
// Created by lukas on 12.12.22.
//
#pragma once

#include "container/ParticleContainer.h"
#include "forceCalculation/LennardJones.h"
/**
 * @brief class to calculate force in case of periodic boundaries
 * first internal offset is configured, then apply is calles
 */
class Periodic {

    /**
     * @brief offset to be added to the current position of the particle
     */
    std::array<double, 3> offset{};
public:
    /**
     * @brief perform force calculation for periodic boundary
     * @param par ParticleContainer containing particles of he opposite side
     * @param p current particle
     * @param fun force calculation routine
     */
    void apply(ParticleContainer& par, Particle& p, std::function<void(Particle &, Particle &)> &fun);

    /**
     * @brief add vertical offset
     * @param domain vertical offset
     */
    void vert(double domain);

    /**
     * @brief add horizontal offset
     * @param domain horizontal offset
     */
    void hor(double domain);
};