//
// Created by dominik on 29.10.22.
//

#include "ForceStrategy.h"

ForceStrategy::ForceStrategy(std::unique_ptr <ForceCalc> &&forceType) : forceType(std::move(forceType)) {}

void ForceStrategy::set_force(std::unique_ptr <ForceCalc> &&newForceType) {
    this->forceType = std::move(newForceType);
}
void ForceStrategy::calculateF(std::list <Particle> &particles){
    forceType->calculateF(particles);
}
