//
// Created by dominik on 05.11.22.
//
#include "Force.h"

class LennardJones : public Force{
public:
    void calculateF(ParticleContainer &particles) override;
    virtual ~LennardJones();
    LennardJones();

private:
    double depthOfPotentialWell;
    double zeroCrossing;
};
