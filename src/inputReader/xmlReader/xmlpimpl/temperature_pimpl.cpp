//
// Created by dominik on 12.12.22.
//

#include "temperature_pimpl.h"

namespace XMLReader {
    void temperature_pimpl::init(std::shared_ptr<Simulation> &simulation) {
        sim = simulation;
    }

    void temperature_pimpl::temp_int(double temp_int) {
        temp = temp_int;
        temp_tar = temp;
    }

    void temperature_pimpl::n_thermostat(int n_thermostat) {
        n_thermo = n_thermostat;
    }

    void temperature_pimpl::temp_target(double temp_target) {
        temp_tar = temp_target;
    }

    void temperature_pimpl::temp_delta(double temp_delta) {
        temp_del = temp_delta;
    }

    void temperature_pimpl::post_temperature() {
        std::shared_ptr<Thermostat> thermostat_p = std::make_shared<Thermostat>(temp);
        thermostat_p->setDelta(temp_del);
        thermostat_p->setTarget(temp_tar);
        sim->setThermostat(thermostat_p);
        sim->setN_thermostat(n_thermo);
    }
}