//
// Created by dominik on 12.12.22.
//

#pragma once

#include "../molsim-pskel.h"
#include "Simulation.h"
#include "tempCalculation/Thermostat.h"

namespace XMLReader {
    class temperature_pimpl : public simulation_pskel {
    private:
        std::shared_ptr<Simulation> sim;
        std::shared_ptr<Thermostat> thermostat;
    public:
        void init(std::shared_ptr<Simulation> &sim);

        void temp_int(double) override;

        void n_thermostat(int) override;

        void temp_target(double) override;

        void temp_delta(double) override;

        void post_temperature() override;
    };
}