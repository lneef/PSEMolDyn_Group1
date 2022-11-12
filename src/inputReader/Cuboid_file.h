//
// Created by dominik on 09.11.22.
//

#pragma once

#include "FileReader.h"
#include "CuboidGenerator.h"

namespace inputReader{
    class Cuboid_file : public FileReader{
    public:
        Cuboid_file(char* filename);
        virtual ~Cuboid_file();
        void read(ParticleContainer &particles) override;
    };
}