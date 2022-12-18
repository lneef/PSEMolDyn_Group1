//
// Created by dominik on 14.12.22.
//

#pragma once

#include <queue>
#include "inputReader/xmlReader/molsim-pskel.h"
#include "Simulation.h"

namespace XMLReader {
    class sphere_pimpl : public sphere_pskel {
    private:
        std::shared_ptr<LinkedCellContainer> cells;
        std::shared_ptr<Simulation> sim;
        std::queue<double> centre;
        int radius_r;
        double width;
        double mass_r;
        std::queue<double> vel;
        bool browMot = true;
        int type_s = 1;
        double sigma_s = 1;
        double epsilon_s = 5;
    public:
        void init(std::shared_ptr<LinkedCellContainer> &lc, std::shared_ptr<Simulation> &sim);

        void center_x(double) override;

        void center_y(double) override;

        void center_z(double) override;

        void radius(int) override;

        void mesh_width(double) override;

        void mass(double) override;

        void velocity_x(double) override;

        void velocity_y(double) override;

        void velocity_z(double) override;

        void brownianMotion(bool) override;

        void type(int) override;

        void sigma(double) override;

        void epsilon(double ) override;

        void post_sphere() override;

        //bool checkZeroVelocity(std::array<double, 3> v);
    };
}
