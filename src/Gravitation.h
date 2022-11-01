//
// Created by dominik on 27.10.22.
//
#include "Force.h"
#include <cmath>

class Gravitation : public Force {
public:
    void calculateF(ParticleContainer &particles) override;

private:
    double calculateNorm(std::array<double, 3> x);
};
