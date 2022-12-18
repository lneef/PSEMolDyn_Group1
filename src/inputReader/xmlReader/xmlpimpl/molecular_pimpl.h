//
// Created by lukas on 01.12.22.
//
#pragma once


#include "inputReader/xmlReader/molsim-pskel.h"
#include "simulation_pimpl.h"
#include "cuboid_input_pimpl.h"
#include "cuboid_pimpl.h"
#include "spheres_input_pimpl.h"
#include "boundaries_impl.h"
#include "temperature_pimpl.h"
#include "sphere_pimpl.h"

namespace XMLReader {
    class molecular_pimpl : public molecular_pskel {
    public:

        void pre() override;
        /**
         * @brief Function that initializes the container and the simulation
         */
        void init(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc);

        void cuboid() override;

        void simulation() override;

        void cuboid_input() override;

        void spheres_input() override;

        void sphere() override;

        void boundaries() override;

        void temperature() override;

        void from_checkpoint() override;

        void post_molecular() override;
    };

}