//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../Cuboid_XMLFile.h"


class input_pimpl : public virtual input_pskel {
protected:
    std::vector<std::string> input_path;
    inputReader::Cuboid_XMLFile file;
public:
    virtual void pre(inputReader::Cuboid_XMLFile file);

    virtual void path(const ::std::string &);

    virtual void post_input();
};