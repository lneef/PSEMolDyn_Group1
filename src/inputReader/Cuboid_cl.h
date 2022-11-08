//
// Created by dominik on 05.11.22.
//

#pragma once

#include "../Particle.h"
#include "../ParticleContainer.h"
#include "InputReader.h"

namespace inputReader {
    class Cuboid_cl : public InputReader{
    public:
        Cuboid_cl();

        virtual ~Cuboid_cl();

        void read(ParticleContainer &particles) override;
    };
}