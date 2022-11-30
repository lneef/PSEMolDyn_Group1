//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"

class boundaries_pimpl : public virtual boundaries_pskel {
public:
    virtual void pre();

    virtual void post_boundaries();
};