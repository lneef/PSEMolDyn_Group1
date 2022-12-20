#include <iostream>
#include "LennardJones.h"
#include "container/ParticleContainer.h"

LennardJones::~LennardJones() = default;

//calculation new force with Lennard-Jones potential

void LennardJones::calculateF(std::shared_ptr<Container>& particles) {

    particles->apply([](Particle& p) {
        p.updateF({});
        });
    particles->applyF([](Particle& p1, Particle& p2) {
        calculateF(p1, p2);
        });

}

LennardJones::LennardJones() = default;

void LennardJones::calculateF(Particle& p1, Particle& p2) {
    double sigma, epsilon;
    if (p1.getType() == p2.getType()) {
        sigma = p1.getSigma();
        epsilon = p1.getEpsilon();
    }
    else {
        sigma = (p1.getSigma() + p2.getSigma()) / 2.;
        epsilon = std::sqrt(p1.getEpsilon() * p2.getEpsilon());
    }

    std::array<double, 3> xij = p1.getX() - p2.getX();

    double sum = xij[0] * xij[0] + xij[1] * xij[1] + xij[2] * xij[2];
    double pow_6 = pow((sigma * sigma)/sum, 3);
    double scalar = ((-24 * epsilon) / sum) * (pow_6 - 2 * pow(pow_6, 2));
    std::array<double, 3> newF = scalar * xij;
    p1.setF(p1.getF() + newF);  p2.setF(p2.getF() - newF);

    // double norm = ArrayUtils::L2Norm(xij);
    // double pow_6 = pow((sigma / norm), 6);
    // double scalar = ((-24 * epsilon) / pow(norm, 2)) * (pow_6 - 2 * pow(pow_6, 2));
    // std::array<double, 3> newF = scalar * xij;
    // p1.setF(p1.getF() + newF);
    // p2.setF(-1 * newF + p2.getF());
}


