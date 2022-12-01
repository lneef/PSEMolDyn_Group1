//
// Created by dominik on 27.10.22.
//
#include "Force.h"

/**
 * @brief Gravitation implements the interface provided by Force
 * 
 * Gravitation implements the interface provided by Force for calculating the gravitation between particles.
*/
class Gravitation : public Force {
public:
    /**
     * @brief Overriden calculateF of Force to be used to calculate the gravitation between particles.
     * 
     * @param particles ParticleContainer containing particles for which the effective force acting on the is calculated.
    */
    void calculateF(std::shared_ptr<Container> &particles) override;

     ~Gravitation() override;
};
