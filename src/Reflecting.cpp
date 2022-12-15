//
// Created by lukas on 04.12.22.
//

#include <iostream>
#include "Reflecting.h"



bool Reflecting::check(const Particle &p) {
    double critical = p.getSigma() * 1.224;
    return 2 * std::abs(difference((p))) < critical;
}

double Reflecting::difference(const Particle &p) {
    double diff = 0.;
    auto & pos = p.getX();

    //get entry for the dimension of the boundary
    for(size_t i = 0; i< 3; ++i) {
        diff += indicator[i] * pos[i];
    }
    return border - diff;
}


Reflecting::Reflecting(std::array<double, 3> &indicator_arg, double border) {
    indicator=indicator_arg;
    this->border= border;
}


