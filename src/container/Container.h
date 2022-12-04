//
// Created by lukas on 29.11.22.
//

#pragma once

#include <functional>
#include "Particle.h"

class Container {
public:
    virtual void apply(std::function<void(Particle &)> fun) = 0;

    virtual void applyX(std::function<void(Particle &)> fun) = 0;

    virtual ~Container();

    virtual void applyF(std::function<void(Particle &, Particle &)> fun) = 0;

    virtual size_t size() = 0;

    virtual void addParticle(Particle &p) = 0;

    virtual void addParticle(Particle &&p) = 0;
};


