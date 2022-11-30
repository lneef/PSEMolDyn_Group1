//
// Created by dominik on 26.11.22.
//
#pragma once

#include "../cuboid-pskel.h"
#include "../Cuboid_XMLFile.h"

class output_pimpl : public virtual output_pskel {
protected:
    inputReader::Cuboid_XMLFile file;
public:
    virtual void pre(inputReader::Cuboid_XMLFile file);

    virtual void name(const ::std::string &);

    virtual void frequency(int);

    virtual void post_output();
};