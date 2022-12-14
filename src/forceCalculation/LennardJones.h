
#pragma once
#include "Force.h"
#include "container/ParticleContainer.h"

/**
 * @brief LennardJones implements the interface provided by Force
 *
 * LennardJones implements the interface provided by Force for calculating the force between particles with the Lennard-Jones potential.
*/
class LennardJones : public Force {
public:

    /**
     * @brief calculates the force effective on the particles inside the given container
     * @param particles Container holding the particles for which the force is calculated
     */
    void calculateF(std::shared_ptr<Container>  &particles) override;

    ~LennardJones() override;

    /**
     * @brief constructor of LennardJones
     */
    explicit LennardJones();

};
