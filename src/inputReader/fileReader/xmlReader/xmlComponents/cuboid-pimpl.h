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
#include "../Cuboid_XMLFile.h"

class cuboid_pimpl : public virtual cuboid_pskel {
protected:
    std::vector<double> position;
    std::vector<int> quantity;
    double distance;
    double mass;
    std::vector<double> velocity;
    inputReader::Cuboid_XMLFile file;

public:
    virtual void pre(inputReader::Cuboid_XMLFile file);

    virtual void x(double);

    virtual void n(int);

    virtual void h(double);

    virtual void m(double);

    virtual void v(double);

    virtual void post_cuboid();
};