//
// Created by dominik on 12.12.22.
//

#pragma once

#include "../molsim-pskel.h"
#include "Simulation.h"
#include "utils//Thermostat.h"

namespace XMLReader {
    class temperature_pimpl : public XMLReader::temperature_pskel {
    private:
        std::shared_ptr<Simulation> sim;
        double temp;
        int n_thermo;
        double temp_tar;
        double temp_del =  std::numeric_limits<double>::infinity();
    public:
        /**
         * @brief initializes the parser with a instance of Simulation
         * @param sim reference to shared pointer pointing to instance of Simulation
         */
        void init(std::shared_ptr<Simulation> &sim);

        void temp_int(double) override;

        void n_thermostat(int) override;

        void temp_target(double) override;

        void temp_delta(double) override;

        void post_temperature() override;
    };
}