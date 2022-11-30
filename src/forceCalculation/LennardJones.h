
#include "Force.h"
#include "container/ParticleContainer.h"

/**
 * @brief LennardJones implements the interface provided by Force
 *
 * LennardJones implements the interface provided by Force for calculating the force between particles with the Lennard-Jones potential.
*/
class LennardJones : public Force {
public:
    void calculateF(std::unique_ptr<Container>  &particles) override;

    ~LennardJones() override;

    explicit LennardJones(double zeroCrossing_arg = 1, double depthOfPotentialWell_arg = 5);

private:
    double depthOfPotentialWell;
    double zeroCrossing;
};
