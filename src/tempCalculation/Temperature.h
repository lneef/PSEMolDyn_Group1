//
// Created by dominik on 10.12.22.
//
#pragma once

#include "container/ParticleContainer.h"
#include "Thermostat.h"
#include "Particle.h"
#include <memory>
#include <math.h>

class Temperature {
public:
    ~Temperature();

    /**
     * @brief calculates the velocity of the particles inside the given container and a new temperature
     * @param particles Container holding the particles for which the velocity is calculated
     * @param thermostat Thermostat holding the temperature parameters
     */
    void calculateV(std::shared_ptr<Container> &particles, std::shared_ptr<Thermostat> &thermostat);

    /**
     * @brief calculates the product of a vector
     * @param v vector for which the product is calculated
     * @return the product of the vector
     */
    double calculateProduct(std::array<double, 3> v);
};