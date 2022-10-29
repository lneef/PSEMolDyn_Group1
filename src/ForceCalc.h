//
// Created by dominik on 27.10.22.
//
#pragma once

#include <list>
#include "Particle.h"

class ForceCalc {

public:
    ~ForceCalc();

    virtual void calculateF(std::list <Particle> &particles) = 0;
};