

#include "Gravitation.h"

//calculation new force
void Gravitation::calculateF(ParticleContainer &particles) {

    particles.apply([](Particle &p){
       p.updateF({});
    });

    size_t len = particles.size();

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            Particle &p1 = particles[i];
            Particle &p2 = particles[j];

            std::array<double, 3> xij = p1.getX() - p2.getX();
            std::array<double, 3> xji = p2.getX() - p1.getX();
            double norm = ArrayUtils::L2Norm(xij);
            std::array<double, 3> newF{};
            double scalar = p1.getM() * p2.getM() / pow(norm, 3);

            newF = scalar * xji;
            p1.setF(p1.getF() + newF);
            p2.setF(-1 * newF + p2.getF());
        }
    }
}

Gravitation::~Gravitation() = default;
