//
// Created by lukas on 04.12.22.
//

#include "Reflecting.h"

double Reflecting::critical = 0;

bool Reflecting::check(const Particle &p) {
    return 2 * std::abs(difference((p))) < critical;
}

double Reflecting::difference(const Particle &p) {
    double diff = 0.;
    auto & pos = p.getX();
    for(size_t i = 0; i< 3; ++i) {
        diff += indicator[i] * pos[i];
    }
    return border - diff;
}

void Reflecting::init_bound(double sigma){
    critical = 1.1225 * sigma;
}

Reflecting::Reflecting(std::array<double, 3> &indicator_arg, double border) {
    indicator=indicator_arg;
    this->border= border;
}

Reflecting::~Reflecting() = default;

