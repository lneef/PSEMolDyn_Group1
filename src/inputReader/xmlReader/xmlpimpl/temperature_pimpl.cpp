//
// Created by dominik on 12.12.22.
//

#include "temperature_pimpl.h"

namespace XMLReader{
    void temperature_pimpl::init(std::shared_ptr<Simulation> &sim) {
        sim = sim;
        thermostat = sim->getThermostat();
    }

    void temperature_pimpl::temp_int(double temp_int){
        thermostat->setTemp(temp_int);
    }

    void temperature_pimpl::n_thermostat(int n_thermostat){
        sim->setN_thermostat(n_thermostat);
    }

    void temperature_pimpl::temp_target(double temp_target){
        thermostat->setTemp_target(temp_target);
    }

    void temperature_pimpl::temp_delta(double temp_delta){
        thermostat->setTemp_delta(temp_delta);
    }

    void temperature_pimpl::post_temperature(){

    }
}