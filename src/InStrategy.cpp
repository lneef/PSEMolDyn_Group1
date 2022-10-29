//
// Created by dominik on 29.10.22.
//

#include "InStrategy.h"

InStrategy::InStrategy(std::unique_ptr <InGeneral> &&inputType) : inputType(std::move(inputType)) {}

void InStrategy::set_input(std::unique_ptr <InGeneral> &&newInputType) {
    this->inputType = std::move(newInputType);
}

void InStrategy::readFile(std::list <Particle> &particles, char *filename) {
    inputType->readFile(particles, filename);
}