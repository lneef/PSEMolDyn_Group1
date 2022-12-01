//
// Created by lukas on 01.12.22.
//
#pragma once

#include <queue>
#include "inputReader/xmlReader/molsim-pskel.h"
#include "container/LinkedCellContainer.h"

class cuboid_pimpl : public cuboid_pskel{
private:
    std::shared_ptr<LinkedCellContainer> cells;
    std::vector<double> pos;
    std::vector<int> num;
    std::vector<double> vel;
    double mass;
    double width;
public:
    void init(std::shared_ptr<LinkedCellContainer> &lc);

    void x (double) override;

    void y (double) override;

    void z (double) override;

    void n_x (int) override;

    void n_y (int) override;

    void n_z (int) override;

    void h (double) override;

    void m (double) override;

    void v_x (double) override;

    void v_y (double) override;

    void v_z (double) override;


    void post_cuboid () override;
};



