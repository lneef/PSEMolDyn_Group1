//
// Created by dominik on 26.11.22.
//

#include "cuboid-pimpl.h"

void cuboid_pimpl::pre(std::vector<std::array<double, 3>> &positions,
                       std::vector<std::array<int, 3>> &quantities,
                       std::vector<double> &distances,
                       std::vector<double> &masses,
                       std::vector<std::array<double, 3>> &velocities) {
    this->positions = positions;
    this->quantities = quantities;
    this->distances = distances;
    this->masses = masses;
    this->velocities = velocities;

}

void cuboid_pimpl::x(double x) {
    position.push_back(x);
}

void cuboid_pimpl::n(int n) {
    quantity.push_back(n);
}

void cuboid_pimpl::h(double h) {
    distance = h;
}

void cuboid_pimpl::m(double m) {
    mass = m;
}

void cuboid_pimpl::v(double v) {
    velocity.push_back(v);
}

void cuboid_pimpl::post_cuboid() {
    std::array<double, 3> pos;
    std::array<int, 3> quan;
    std::array<double, 3> vel;
    for (int i = 0; i < 3; i++) {
        pos[i] = position[i];
        quan[i] = quantity[i];
        vel[i] = velocity[i];
    }
    positions.push_back(pos);
    quantities.push_back(quan);
    distances.push_back(distance);
    masses.push_back(mass);
    velocities.push_back(vel);
}