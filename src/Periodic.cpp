//
// Created by lukas on 12.12.22.
//

#include <iostream>
#include "Periodic.h"

#include "Periodic.h"
#include "utils/ArrayUtils.h"
#include "MolSimLogger.h"

void Periodic::vert(double domain) {
    offset[1] = domain;
}

void Periodic::hor(double domain) {
    offset[0] = domain;
}


void Periodic::apply(ParticleContainer& par, Particle& p, std::function<void(Particle &, Particle &)> &fun) {
    Particle par_mirror(p.getX() + offset, p.getV(), p.getM());
    auto partial = [&par_mirror, &fun](Particle& p1){
        fun(par_mirror, p1);
    };
    par.apply(partial);
    MolSimLogger::logDebug("Offset for periodic boundary: {} {} {}", offset[0], offset[1], offset[2]);
    MolSimLogger::logDebug("Force effective on mirrored particle: {} {} {}" , par_mirror.getF()[0], par_mirror.getF()[1], par_mirror.getF()[2]);
    p.setF(p.getF() + par_mirror.getF());
}