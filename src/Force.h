//
// Created by dominik on 27.10.22.
//
#pragma once

#include "ParticleContainer.h"
#include "Particle.h"

class Force {

public:

	virtual void calculateF(ParticleContainer &particles) = 0;
};
