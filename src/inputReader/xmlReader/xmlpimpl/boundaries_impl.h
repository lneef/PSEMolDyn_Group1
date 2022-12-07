//
// Created by dominik on 03.12.22.
//

#pragma once

#include "inputReader/xmlReader/molsim-pskel.h"
#include "container/LinkedCellContainer.h"
#include <array>

namespace XMLReader {
    /**
     * @brief boundaries_pimpl implements the parser which reads the boundary conditions
     */
    class boundaries_pimpl : public boundaries_pskel {
    public:
        /**
         * @brief Function that reads the top condition
         */
        void top(const ::std::string &) override;
        /**
         * @brief Function that reads the bottom condition
         */
        void bottom(const ::std::string &) override;
        /**
         * @brief Function that reads the left condition
         */
        void left(const ::std::string &) override;
        /**
         * @brief Function that reads the right condition
         */
        void right(const ::std::string &) override;

        void post_boundaries() override;

        void init(std::shared_ptr<LinkedCellContainer>& cells_arg);

    private:
        std::array<double, 3> hor{0, 1, 0};
        std::array<double, 3> vert{1, 0, 0};

        std::shared_ptr<LinkedCellContainer> cells;
    };
}
