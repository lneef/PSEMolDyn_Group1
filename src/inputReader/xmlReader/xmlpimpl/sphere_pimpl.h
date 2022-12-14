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
        int radius;
        double width;
        double mass;
        std::queue<double> vel;
    public:
        void init(std::shared_ptr<LinkedCellContainer> &lc, std::shared_ptr<Simulation> &sim);

        void x(double) override;

        void y(double) override;

        void z(double) override;

        void r(int) override;

        void h(double) override;

        void m(double) override;

        void v_x(double) override;

        void v_y(double) override;

        void v_z(double) override;

        void post_sphere() override;

        bool checkZeroVelocity(std::array<double, 3> v);
    };
}
