//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"


class input_pimpl : public virtual input_pskel {
protected:
    std::vector<std::string> input_path;
public:
    virtual void pre(std::vector<std::string> &input_path);

    virtual void path(const ::std::string &);

    virtual void post_input();
};