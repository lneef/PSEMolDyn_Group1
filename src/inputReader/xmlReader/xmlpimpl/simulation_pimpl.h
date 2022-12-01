//
// Created by lukas on 01.12.22.
//

#pragma once

#include <queue>
#include "../molsim-pskel.h"
#include "container/LinkedCellContainer.h"
#include "Simulation.h"

class simulation_pimpl : public simulation_pskel {
private:
    std::shared_ptr<LinkedCellContainer> cells;
    std::shared_ptr<Simulation> sim;
    std::queue<double> domain{};
    double rCutOff;
public:
    void init(std::shared_ptr<LinkedCellContainer> &cells_arg, std::shared_ptr<Simulation> &simu);

    void t_end(double) override;

    void delta_t(double) override;

    void domain_x(double) override;

    void domain_y(double) override;

    void domain_z(double) override;

    void domain_cutOf(double) override;

    void name(const ::std::string &) override;

    void frequency(int) override;

    void post_simulation() override;
};

