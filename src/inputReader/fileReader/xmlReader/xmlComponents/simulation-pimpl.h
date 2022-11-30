//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../Cuboid_XMLFile.h"

class simulation_pimpl : public virtual simulation_pskel {
protected:
    double end_time;
    double delta_time;
    double dom_size;
    double dom_cutOf;
    inputReader::Cuboid_XMLFile file;
public:
    virtual void pre(inputReader::Cuboid_XMLFile file);

    virtual void t_end(double);

    virtual void delta_t(double);

    virtual void domain_size(double);

    virtual void domain_cutOf(double);

    virtual void post_simulation();
};