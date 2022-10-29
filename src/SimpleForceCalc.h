//
// Created by dominik on 27.10.22.
//
#include "ForceCalc.h"
#include <cmath>

class SimpleForceCalc : public ForceCalc {
public:
    void calculateF(std::list <Particle> &particles) override;

private:
    double calculateNorm(std::array<double, 3> x);
};