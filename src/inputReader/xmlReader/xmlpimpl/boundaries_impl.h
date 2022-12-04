//
// Created by dominik on 03.12.22.
//

#pragma once

#include "inputReader/xmlReader/molsim-pskel.h"

namespace XMLReader {
    class boundaries_pimpl : public boundaries_pskel {
    public:
        void top(const ::std::string &) override;

        void bottom(const ::std::string &) override;

        void left(const ::std::string &) override;

        void right(const ::std::string &) override;

        void post_boundaries() override;
    };
}
