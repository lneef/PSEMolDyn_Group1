//
// Created by dominik on 10.12.22.
//
#pragma once

#include <limits>

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
public:
    Thermostat(double temp_target, double temp);

    Thermostat(double temp);

    /**
     * @brief Getter for the target temperature
     * @return target temperature, which is the temperature you aim to reach
     */
    const double getTemp_target() const;

    /**
     * @brief Getter for the delta temperature
     * @return delta temperature, which is the maximal absolute temperature
     */
    const double getTemp_delta() const;

    /**
     * @brief Getter for the current temperature
     * @return current temperature
     */
    const double getTemp() const;

    /**
     * @brief Setter for the target temperature
     * @param temp_target target temperature, which is the temperature you aim to reach
     */
    void setTemp_target(const double temp_target);

    /**
     * @brief Setter for the delta temperature
     * @param temp_delta delta temperature, which is the maximal absolute temperature
     */
    void setTemp_delta(const double temp_delta);

    /**
     * @brief Setter for the current temperature
     * @param temp current temperature
     */
    void setTemp(const double temp);
};