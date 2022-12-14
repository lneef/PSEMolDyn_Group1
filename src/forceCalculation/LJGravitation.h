#pragma once
#include "Force.h"
#include "LennardJones.h"

/**
 * @brief LJGravitation implements the uniform interface provided by force
 * it implements a force calculation routine that combines the gravitation on the particle with the Lennard Jones potential
 */
class LJGravitation : public Force{
public:
    /**
     * @brief constructor of LJGravitation
     * @param g_arg gravitation constant
     */
    explicit LJGravitation(double g_arg);
    ~LJGravitation() override;

    /**
     * @brief applies the force calculation routine to all particles inside the container
     * @param particles container of particles
     */
    void calculateF(std::shared_ptr<Container>& particles) override;
private:

    /**
     * @brief gravitation constant to calculate the gravitation effective on a particle
     */
    double g;
};
