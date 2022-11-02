//
// Created by dominik on 27.10.22.
//
#include "Force.h"
#include <cmath>

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
    void calculateF(ParticleContainer &particles) override;

    virtual  ~Gravitation();

private:
    /**
     * @brief Calculates Euclidean norm for three dimensional vector.
     * 
     * @param x array of size three representing a three dimensional vector.
     * 
     * @return Euclidian norm of passed vector.
    */
    double calculateNorm(std::array<double, 3> x);
};
