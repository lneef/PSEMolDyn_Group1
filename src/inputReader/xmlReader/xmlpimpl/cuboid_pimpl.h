//
// Created by lukas on 01.12.22.
//
#pragma once

#include <queue>
#include "inputReader/xmlReader/molsim-pskel.h"
#include "container/LinkedCellContainer.h"

namespace XMLReader {
    class cuboid_pimpl : public cuboid_pskel {
    private:
        /**
         * @brief Container containing all linked cells for the simulation
         */
        std::shared_ptr<LinkedCellContainer> cells;
        /**
         * @brief Queue containing the position of the cuboid
         */
        std::queue<double> pos;
        /**
         * @brief Queue containing the quantity of molecules of the cuboid
         */
        std::queue<int> num;
        /**
         * @brief Queue containing the velocity of the cuboid
         */
        std::queue<double> vel;
        /**
         * @brief Mass of the molecules in the cuboid
         */
        double mass;
        /**
         * @brief Distance between the molecules in the cuboid
         */
        double width;
    public:
        /**
         * @brief Function that initializes the container
         */
        void init(std::shared_ptr<LinkedCellContainer> &lc);
        /**
         * @brief Function that reads the position in x-dimension
         */
        void x(double) override;
        /**
         * @brief Function that reads the position in y-dimension
         */
        void y(double) override;
        /**
         * @brief Function that reads the position in z-dimension
         */
        void z(double) override;
        /**
         * @brief Function that reads the quantity in x-dimension
         */
        void n_x(int) override;
        /**
         * @brief Function that reads the quantity in x-dimension
         */
        void n_y(int) override;
        /**
         * @brief Function that reads the quantity in x-dimension
         */
        void n_z(int) override;
        /**
         * @brief Function that reads the distance between the molecules
         */
        void h(double) override;
        /**
         * @brief Function that reads mass of the molecules
         */
        void m(double) override;
        /**
         * @brief Function that reads the velocity in x-dimension
         */
        void v_x(double) override;
        /**
         * @brief Function that reads the velocity in x-dimension
         */
        void v_y(double) override;
        /**
         * @brief Function that reads the velocity in x-dimension
         */
        void v_z(double) override;
        /**
         * @brief Function that generates the cuboids
         */
        void post_cuboid() override;
    };

}

