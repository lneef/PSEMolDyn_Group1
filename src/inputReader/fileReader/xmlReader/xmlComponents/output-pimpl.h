//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../../../../Simulation.h"

class output_pimpl : public virtual output_pskel {
protected:
    std::shared_ptr<Simulation> simulation;
public:
    virtual void pre(std::shared_ptr<Simulation> &simulation);

    virtual void name(const ::std::string &);

    virtual void frequency(int);

    virtual void post_output();
};