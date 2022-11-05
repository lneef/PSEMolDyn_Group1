//
// Created by dominik on 05.11.22.
//
#include "Force.h"

class LennardJones : public Force{
public:
    void calculateF(ParticleContainer &particles) override;
    virtual ~LennardJones();
private:
    double calculateNorm(std::array<double, 3> x);
};
