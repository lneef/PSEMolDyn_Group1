//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../../../../Simulation.h"

class simulation_pimpl : public virtual simulation_pskel {
protected:
    double end_time;
    double delta_time;
    std::shared_ptr<Simulation> simulation;
    double dom_size_ref;
    double dom_cutOf_ref;
public:
    virtual void pre(std::shared_ptr<Simulation> &simulation, double &dom_size_ref, double &dom_cutOf_ref);

    virtual void t_end(double);

    virtual void delta_t(double);

    virtual void domain_size(double);

    virtual void domain_cutOf(double);

    virtual void post_simulation();
};