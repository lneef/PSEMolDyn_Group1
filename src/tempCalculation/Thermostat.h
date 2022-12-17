//
// Created by dominik on 10.12.22.
//
#pragma once

#include "container/ParticleContainer.h"
#include "Particle.h"
#include <memory>
#include <math.h>
#include <limits>
#include "MolSimLogger.h"

class Thermostat {
private:
    /**
     * Target temperature, which is the temperature you aim to reach
     */
    double temp_target;
    /**
     * Delta temperature, which is the maximal absolute temperature
     */
    double temp_delta = std::numeric_limits<double>::infinity();
    /**
     * Current temperature
     */
    double temp;
public:
    Thermostat(double temp_target, double temp);

    Thermostat(double temp);

    ~Thermostat();

    /**
     * @brief calculates the velocity of the particles inside the given container and a new temperature
     * @param particles Container holding the particles for which the velocity is calculated
     */
    void calculateV(std::shared_ptr<Container> &particles);

    /**
     * @brief calculates the product of a vector
     * @param v vector for which the product is calculated
     * @return the product of the vector
     */
    double calculateProduct(std::array<double, 3> v);

    /**
     * @brief Getter for the current temperature
     * @return current temperature
     */
    const double getTemp() const;

    const double getTemp_target() const;

    /**
     * @brief Setter for the target temperature
     * @param temp_target target temperature, which is the temperature you aim to reach
     */
    void setTemp_target(const double temp_target);

    /**
     * @brief Setter for the delta temperature
     * @param temp_delta delta temperature, which is the maximal absolute temperature
     */
    void setTemp_delta(const double temp_delta);

};