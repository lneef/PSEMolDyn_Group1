//
// Created by dominik on 05.11.22.
//

#pragma once

#include "../Particle.h"
#include "../ParticleContainer.h"

namespace inputReader {
    class Cuboid_cl {
    public:
        Cuboid_cl();

        virtual ~Cuboid_cl();

        void readInput(ParticleContainer &particles);
    };
}