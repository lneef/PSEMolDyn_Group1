//
// Created by dominik on 10.12.22.
//
#pragma once

#include <limits>

class Thermostat {
private:
    double temp_target;
    double temp_delta = std::numeric_limits<double>::infinity();
    double temp;
public:
    Thermostat(double temp_target, double temp);

    Thermostat(double temp);

    const double getTemp_target() const;

    const double getTemp_delta() const;

    const double getTemp() const;

    void setTemp_target(const double temp_target);

    void setTemp_delta(const double temp_delta);

    void setTemp(const double temp);
};