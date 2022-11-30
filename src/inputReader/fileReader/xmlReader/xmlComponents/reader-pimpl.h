//
// Created by dominik on 28.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../../../../Simulation.h"
#include "../Cuboid_XMLFile.h"

class reader_pimpl : public virtual reader_pskel {
protected:
    inputReader::Cuboid_XMLFile file;
public:
    virtual void pre(inputReader::Cuboid_XMLFile file);

    virtual void cuboid();

    virtual void simulation();

    virtual void output();

    virtual void boundaries();

    virtual void input();

    virtual void post_reader();
};
