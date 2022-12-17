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

Thermostat::~Thermostat() = default;

void Thermostat::calculateV(std::shared_ptr<Container> &particles) {
    double kin_energy = 0;
    particles->apply([this, &kin_energy](Particle &p) {
        kin_energy = kin_energy + ((p.getM() * Thermostat::calculateProduct(p.getV())) / 2);
    });
    int dimension = 2;
    double temperature_new = ((kin_energy * 2) / (dimension * particles->size()));
    double temp_diff = std::abs(temp - temperature_new);
    if (temp_diff <= temp_delta) {
        double temperature;
        temperature = sqrt(temperature_new / temp);
        temp = temperature_new;
        particles->apply([&temperature](Particle &p) {
            std::array<double, 3> v_new;
            for (int i = 0; i < 3; i++) {
                v_new[i] = temperature * p.getV()[i];
            }
            p.setV(v_new);
        });
    }
}

double Thermostat::calculateProduct(std::array<double, 3> v) {
    double product = 0;
    for (int i = 0; i < 3; i++) {
        product += pow(v[i], 2);
    }
    return product;
}

const double Thermostat::getTemp() const {
    return temp;
}

const double Thermostat::getTemp_target() const { return temp_target; }


void Thermostat::setTemp_target(const double temp_target) {
    this->temp_target = temp_target;
}

void Thermostat::setTemp_delta(const double temp_delta) {
    this->temp_delta = temp_delta;
}