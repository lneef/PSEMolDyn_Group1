//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../../../../container/Container.h"
#include "../../../CuboidGenerator.h"
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include "../../../CuboidGenerator.h"

class cuboid_pimpl : public virtual cuboid_pskel {
protected:
    std::vector<double> position;
    std::vector<int> quantity;
    double distance;
    double mass;
    std::vector<double> velocity;
    std::unique_ptr<Container> particles;

public:
    virtual void pre(std::unique_ptr<Container> &part);

    virtual void x(double);

    virtual void n(int);

    virtual void h(double);

    virtual void m(double);

    virtual void v(double);

    virtual void post_cuboid();
};