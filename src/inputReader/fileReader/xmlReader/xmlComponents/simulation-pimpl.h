//
// Created by dominik on 26.11.22.
//
#include "../cuboid-pskel.h"

class simulation_pimpl: public virtual simulation_pskel
{
public:
    virtual void
    pre ();

    virtual void
    t_end (double);

    virtual void
    delta_t (double);

    virtual void
    post_simulation ();
};