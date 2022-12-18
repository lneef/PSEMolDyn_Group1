//
// Created by lukas on 01.12.22.
//
#pragma once

#include <queue>
#include "inputReader/xmlReader/molsim-pskel.h"
#include "container/LinkedCellContainer.h"
#include "Simulation.h"

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
        double m;
        /**
         * @brief Distance between the molecules in the cuboid
         */
        double width;

        std::shared_ptr<Simulation> sim;

        bool browMot = true;

        int type_p = 1;

        double sigma_p = 1;

        double epsilon_p = 5;
    public:
        /**
         * @brief Function that initializes the container
         */
        void init(std::shared_ptr<LinkedCellContainer> &lc, std::shared_ptr<Simulation> &sim_arg);
        /**
         * @brief Function that reads the position in x-dimension
         */
        void lower_left_x(double) override;
        /**
         * @brief Function that reads the position in y-dimension
         */
        void lower_left_y(double) override;
        /**
         * @brief Function that reads the position in z-dimension
         */
        void lower_left_z(double) override;
        /**
         * @brief Function that reads the quantity in x-dimension
         */
        void number_x(int) override;
        /**
         * @brief Function that reads the quantity in x-dimension
         */
        void number_y(int) override;
        /**
         * @brief Function that reads the quantity in x-dimension
         */
        void number_z(int) override;
        /**
         * @brief Function that reads the distance between the molecules
         */
        void mesh_width(double) override;
        /**
         * @brief Function that reads mass of the molecules
         */
        void mass(double) override;
        /**
         * @brief Function that reads the velocity in x-dimension
         */
        void velocity_x(double) override;
        /**
         * @brief Function that reads the velocity in x-dimension
         */
        void velocity_y(double) override;
        /**
         * @brief Function that reads the velocity in x-dimension
         */
        void velocity_z(double) override;

        void brownianMotion(bool) override;
        /**
         * @brief Function that generates the cuboids
         */

        void type(int) override;

        void sigma(double ) override;

        void epsilon(double ) override;
        void post_cuboid() override;

        //bool checkZeroVelocity(std::array<double, 3> v);
    };

}

