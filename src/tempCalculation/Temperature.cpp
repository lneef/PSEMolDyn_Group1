//
// Created by dominik on 10.12.22.
//

#include "Temperature.h"

Temperature::~Temperature() = default;

void Temperature::calculateV(std::shared_ptr<Container> &particles, std::shared_ptr<Thermostat> &thermostat) {
    double kin_energy = 0;
    particles->apply([this, &kin_energy](Particle &p) {
        kin_energy = kin_energy + ((p.getM() * Temperature::calculateProduct(p.getV())) / 2);
    });
    int dimension = 2;
    double temperature_new = ((kin_energy * 2) / (dimension * particles->size()));
    double temp_diff = abs(thermostat->getTemp() - temperature_new);
    if (temp_diff >= thermostat->getTemp_delta()) {
        double temperature;
        temperature = sqrt(temperature_new / thermostat->getTemp());
        thermostat->setTemp(temperature_new);
        particles->apply([&temperature](Particle &p) {
            std::array<double, 3> v_new;
            for (int i = 0; i < 3; i++) {
                v_new[i] = temperature * p.getV()[i];
            }
            p.setV(v_new);
        });
    }
}

double Temperature::calculateProduct(std::array<double, 3> v) {
    double product = 0;
    for (int i = 0; i < 3; i++) {
        product += pow(v[i], 2);
    }
    return product;
}