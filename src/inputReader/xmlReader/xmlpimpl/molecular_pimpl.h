//
// Created by lukas on 01.12.22.
//
#pragma once


#include "inputReader/xmlReader/molsim-pskel.h"
#include "simulation_pimpl.h"
#include "cuboid_input_pimpl.h"
#include "cuboid_pimpl.h"

class molecular_pimpl : public molecular_pskel{
private:

public:

    void pre() override;
    void init(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc);
    void cuboid () override;

    void simulation () override;

    void cuboid_input () override;

    void post_molecular () override;
};

