//
// Created by dominik on 29.10.22.
//
#pragma once

#include <list>
#include "Particle.h"

class InGeneral {
public:
    InGeneral();

    ~InGeneral();

    virtual void readFile(std::list <Particle> &particles, char *filename) = 0;
};