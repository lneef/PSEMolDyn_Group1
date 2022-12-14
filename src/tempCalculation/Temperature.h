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

    void calculateV(std::shared_ptr<Container> &particles, std::shared_ptr<Thermostat> &thermostat);
    double calculateProduct(std::array<double, 3> v);
};