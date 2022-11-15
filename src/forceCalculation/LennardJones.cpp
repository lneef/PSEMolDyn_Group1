

#include "LennardJones.h"

LennardJones::~LennardJones() = default;

LennardJones::LennardJones() {
    zeroCrossing = 1;
    depthOfPotentialWell = 5;
}

//calculation new force with Lennard-Jones potential
void LennardJones::calculateF(ParticleContainer &particles) {

    particles.apply([](Particle &p){
        p.updateF({});
    });

    size_t len = particles.size();

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            Particle &p1 = particles[i];
            Particle &p2 = particles[j];

            std::array<double, 3> xij = p1.getX() - p2.getX();
            double norm = ArrayUtils::L2Norm(xij);
            double pow_6 = pow((zeroCrossing / norm), 6);
            double scalar = ((-24 * depthOfPotentialWell) / pow(norm, 2)) * (pow_6 - 2 * pow(pow_6, 2));
            std::array<double, 3> newF = scalar * xij;
            p1.setF(p1.getF() + newF);
            p2.setF(-1 * newF + p2.getF());
        }
    }
}

