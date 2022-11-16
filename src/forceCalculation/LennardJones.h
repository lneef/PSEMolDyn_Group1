
#include "Force.h"

/**
 * @brief LennardJones implements the interface provided by Force
 *
 * LennardJones implements the interface provided by Force for calculating the force between particles with the Lennard-Jones potential.
*/
class LennardJones : public Force {
public:
    void calculateF(ParticleContainer &particles) override;

    ~LennardJones() override;

    LennardJones();

private:
    double depthOfPotentialWell;
    double zeroCrossing;
};
