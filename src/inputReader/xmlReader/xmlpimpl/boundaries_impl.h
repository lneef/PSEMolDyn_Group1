//
// Created by dominik on 03.12.22.
//

#pragma once

#include "inputReader/xmlReader/molsim-pskel.h"
#include "container/LinkedCellContainer.h"
#include <array>

namespace XMLReader {
    class boundaries_pimpl : public boundaries_pskel {
    public:
        void top(const ::std::string &) override;

        void bottom(const ::std::string &) override;

        void left(const ::std::string &) override;

        void right(const ::std::string &) override;

        void post_boundaries() override;

        void init(std::shared_ptr<LinkedCellContainer>& cells_arg);

    private:
        std::array<double, 3> hor{0, 1, 0};
        std::array<double, 3> vert{1, 0, 0};

        std::shared_ptr<LinkedCellContainer> cells;
    };
}
