//
// Created by dominik on 28.10.22.
//

#include "ForceCalc.h"

class DefaultForce : public ForceCalc{
public:
    void calculateF(std::list <Particle> &particles) override;
};