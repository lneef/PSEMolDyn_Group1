//
// Created by lukas on 04.12.22.
//

#include "BoundaryCell.h"


BoundaryCell::BoundaryCell(ParticleList &ref): ref(ref) {
}

ParticleList &BoundaryCell::get() {
    return ref;
}
