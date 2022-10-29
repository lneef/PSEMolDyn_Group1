//
// Created by dominik on 29.10.22.
//
#pragma once

#include "InGeneral.h"
#include <memory>

class InStrategy {
private:
    std::unique_ptr <InGeneral> inputType;
public:
    explicit InStrategy(std::unique_ptr <InGeneral> &&inputType = {});

    void set_input(std::unique_ptr <InGeneral> &&newInputType);

    void readFile(std::list <Particle> &particles, char *filename);
};