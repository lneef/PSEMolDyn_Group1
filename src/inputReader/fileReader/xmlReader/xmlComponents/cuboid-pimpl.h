//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../../../../container/Container.h"
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

class cuboid_pimpl : public virtual cuboid_pskel {
protected:
    std::vector<double> position;
    std::vector<int> quantity;
    double distance;
    double mass;
    std::vector<double> velocity;

    std::vector<std::array<double, 3>> positions;
    std::vector<std::array<int, 3>> quantities;
    std::vector<double> distances;
    std::vector<double> masses;
    std::vector<std::array<double, 3>> velocities;

public:
    virtual void pre(std::vector<std::array<double, 3>> &positions,
                     std::vector<std::array<int, 3>> &quantities,
                     std::vector<double> &distances,
                     std::vector<double> &masses,
                     std::vector<std::array<double, 3>> &velocities);

    virtual void x(double);

    virtual void n(int);

    virtual void h(double);

    virtual void m(double);

    virtual void v(double);

    virtual void post_cuboid();
};