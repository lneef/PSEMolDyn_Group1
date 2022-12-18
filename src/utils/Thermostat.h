#pragma once
#include "limits"
#include "memory"
#include "container/Container.h"
class Thermostat {
private:
    /**
     * Target temperature, which is the temperature you aim to reach
     */
    double temp_target;
    /**
     * Delta temperature, which is the maximal absolute temperature
     */
    double temp_delta = std::numeric_limits<double>::infinity();
    /**
     * Current temperature
     */
    double temp;

    static double scalarProduct(Particle& p);

public:
    void applyThermostat(std::shared_ptr<Container>& particles);

    double measureTemp(std::shared_ptr<Container>& particles);

    Thermostat(double current);

    double getTemp();
    void setTarget(double target);
    void setDelta(double delta);
    void setCurrent(double current);
};

