//
// Created by dominik on 10.12.22.
//

#include "Thermostat.h"

Thermostat::Thermostat(double temp) {
    this->temp = temp;
}

Thermostat::Thermostat(double temp_target, double temp) {
    this->temp_target = temp_target;
    this->temp = temp;
}

const double Thermostat::getTemp() const {
    return temp;
}

const double Thermostat::getTemp_target() const {
    return temp_target;
}

const double Thermostat::getTemp_delta() const {
    return temp_delta;
}

void Thermostat::setTemp(const double temp) {
    this->temp = temp;
}

void Thermostat::setTemp_target(const double temp_target) {
    this->temp_target = temp_target;
}

void Thermostat::setTemp_delta(const double temp_delta) {
    this->temp_delta = temp_delta;
}