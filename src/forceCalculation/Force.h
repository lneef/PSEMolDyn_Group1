//
// Created by dominik on 27.10.22.
//
#pragma once
#include "utils/ArrayUtils.h"
#include "../ParticleContainer.h"
#include "../Particle.h"
#include <cmath>

/**
 * @brief Force provides a uniform interface for calculating the effective force between particles
 * 
 * The class provides an abstract method calculateF() which is then implemented by its subclasses. This enables easier extensibility and integration of the methods for calculating the force
 * between particles.
*/
class Force {

public:
    /**
     * @brief calculates the effective force between the passed particles and stores the effective force acting on a particle in the respective field of Particle
     *
     * @param particles ParticleContainer which contains the elements for which effective forces are calculted
     *
     * @see Particle
    */
    virtual void calculateF(ParticleContainer &particles) = 0;

    /**
     * @brief virtual destructor to prevent memory leaks
    */
    virtual ~Force();
};
