//
// Created by lukas on 01.12.22.
//
#pragma once

#include "inputReader/xmlReader/molsim-pskel.h"

namespace XMLReader {
    class cuboid_input_pimpl : public cuboid_input_pskel {
    public:
        void path(const ::std::string &) override;

        void post_cuboid_input() override;
    };

}

