//
// Created by lukas on 01.12.22.
//

#include "simulation_pimpl.h"

void simulation_pimpl::t_end(double end_t) {
    sim->setEndTime(end_t);
}

void simulation_pimpl::delta_t(double delta_t) {
    sim->setDeltaT(delta_t);
}

void simulation_pimpl::domain_x(double x) {
    domain.push_back(x);
}

void simulation_pimpl::domain_y(double y) {
    domain.push_back(y);
}

void simulation_pimpl::domain_z(double z) {
    domain.push_back(z);
}

void simulation_pimpl::domain_cutOf(double cutOff) {
    rCutOff = cutOff;
}

void simulation_pimpl::name(const std::string &name) {
    sim->setOut_name(name);
}

void simulation_pimpl::frequency(int f) {
    sim->setOut_frequency(f);
}

void simulation_pimpl::post_simulation() {
    std::array<double, 3> dom{};
    for (size_t i = 0; i < domain.size() && i < 3; ++i) {
        dom[i] = domain[i];
    }
    cells->setSize(rCutOff,dom);
}


void simulation_pimpl::init(std::shared_ptr<LinkedCellContainer> &cells_arg, std::shared_ptr<Simulation> &simu) {
    cells = cells_arg;
    sim = simu;
}


