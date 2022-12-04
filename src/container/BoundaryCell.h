//
// Created by lukas on 04.12.22.
//

#pragma once


#include "ParticleList.h"

class BoundaryCell {
private:
    ParticleList& ref;
public:

    ParticleList& get();


    explicit BoundaryCell(ParticleList &ref);
};


