//
// Created by dominik on 03.12.22.
//

#pragma once

#include "inputReader/xmlReader/molsim-pskel.h"

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
    };
}
