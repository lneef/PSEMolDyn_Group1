
#pragma once
#include "Force.h"
#include "container/ParticleContainer.h"

/**
 * @brief LennardJones implements the interface provided by Force
 *
 * LennardJones implements the interface provided by Force for calculating the force between particles with the Lennard-Jones potential.
*/
class LennardJones : public Force {
    /**
     * @brief map to store already calculated sigma and epsilon values
     */
    static std::map<std::pair<int, int>, std::pair<int, int>> lookup;
public:

    /**
     * @brief calculates the force effective on the particles inside the given container
     * @param particles Container holding the particles for which the force is calculated
     */
    void calculateF(std::shared_ptr<Container>  &particles) override;

    /**
     * @brief calculates the force between two particles based on the Lennard Jones potential
     * @param p1 first particle of the interaction
     * @param p2 second particle of the interaction
     */
    static void calculateF(Particle& p1, Particle& p2);

    ~LennardJones() override;

    /**
     * @brief constructor of LennardJones
     */
    explicit LennardJones();

};
