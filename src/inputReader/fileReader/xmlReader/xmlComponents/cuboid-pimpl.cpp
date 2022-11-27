//
// Created by dominik on 26.11.22.
//

#include "cuboid-pimpl.h"

void cuboid_pimpl::pre(ParticleContainer part) {
    particles = part;
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
    CuboidGenerator generator;
    generator.generateCuboid(particles, pos, quan, distance, mass, vel);
}