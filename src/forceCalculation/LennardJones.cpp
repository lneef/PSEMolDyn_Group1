

#include "LennardJones.h"
#include "container/ParticleContainer.h"

LennardJones::~LennardJones() = default;

//calculation new force with Lennard-Jones potential
<<<<<<< HEAD

void LennardJones::calculateF(std::shared_ptr<Container> &particles) {

=======
void LennardJones::calculateF(std::shared_ptr<Container> &particles) {

>>>>>>> a5cddadf75a759f6532f0402a30d3292ec43f52e
    particles->apply([](Particle &p) {
        p.updateF({});
    });

    particles->applyF([this](Particle &p1, Particle &p2) {
<<<<<<< HEAD
        std::array<double, 3> xij = p1.getX() - p2.getX();
        double norm = ArrayUtils::L2Norm(xij);
        double pow_6 = pow((zeroCrossing / norm), 6);
        double scalar = ((-24 * depthOfPotentialWell) / pow(norm, 2)) * (pow_6 - 2 * pow(pow_6, 2));

        std::array<double, 3> newF = scalar * xij;
        p1.setF(p1.getF() + newF);
        p2.setF(-1 * newF + p2.getF());
    });
=======
                          std::array<double, 3> xij = p1.getX() - p2.getX();
                          double norm = ArrayUtils::L2Norm(xij);
                          double pow_6 = pow((zeroCrossing / norm), 6);
                          double scalar = ((-24 * depthOfPotentialWell) / pow(norm, 2)) * (pow_6 - 2 * pow(pow_6, 2));
                          std::array<double, 3> newF = scalar * xij;
                          p1.setF(p1.getF() + newF);
                          p2.setF(-1 * newF + p2.getF());
                      }
    );
>>>>>>> a5cddadf75a759f6532f0402a30d3292ec43f52e
}

LennardJones::LennardJones(double zeroCrossing_arg, double depthOfPotentialWell_arg) {
    zeroCrossing = zeroCrossing_arg;
    depthOfPotentialWell = depthOfPotentialWell_arg;
}

