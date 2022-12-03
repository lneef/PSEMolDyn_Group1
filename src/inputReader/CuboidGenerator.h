
#pragma once

#include <memory>
#include <iostream>
#include "../utils/MaxwellBoltzmannDistribution.h"
#include "container/ParticleContainer.h"
#include "utils/ArrayUtils.h"

/**
 * @brief CuboidGenerator generates cuboids of particles form input values
 *
 * CuboidGenerator generates cuboids of particles form input values, which are collected by instances of Cuboid_file or Cuboid_cl.
*/
template<typename T>
class CuboidGenerator {
private:
    double meanV = 0.1;

    /**
     * @brief Calculates velocity of particles with given velocity and the MaxwellBoltzmannDistribution
     *
     * @param v Array representaion of the velocities of the particles in all three dimensions
     * @return velocity with thermal friction
    */
    std::array<double, 3> calculateV(std::array<double, 3> v) {
        MaxwellBoltzmannDistribution mb;
        //calculate velocity with thermal friction
        std::array<double, 3> mbV = mb.maxwellBoltzmannDistributedVelocity(meanV, 2);
        std::array<double, 3> newV{};
        for (int i = 0; i < 3; i++) {
            newV[i] = v[i] + mbV[i];
        }
        return newV;
    }

public:
    CuboidGenerator() = default;

    virtual ~CuboidGenerator() = default;

    /**
     * @brief Generates cuboids of particles with given values and stores them in instance of ParticleContainer
     *
     * @param particles ParticleContainer where the particles are stored
     * @param x Array represention three dimensional position of the particle
     * @param n Array representation of quantity of particles in each dimension
     * @param h Integer representation of distance between the particles
     * @param m Integer representation of mass of one particle
     * @param v Array representaion of the velocities of the particles in all three dimensions
    */
    void
    generateCuboid(std::shared_ptr<T> &particles, std::array<double, 3> x, std::array<int, 3> n, double h, double m,
                   std::array<double, 3> v) {

        std::array<double, 3> newX{};
        //iterate over cuboid in each dimension
        for (int x_cord = 0; x_cord < n[0]; x_cord++) {
            newX[0] = x[0] + (x_cord * h);
            for (int y_cord = 0; y_cord < n[1]; y_cord++) {
                newX[1] = x[1] + (y_cord * h);
                for (int z_cord = 0; z_cord < n[2]; z_cord++) {
                    newX[2] = x[2] + (z_cord * h);
                    std::array<double, 3> newV = calculateV(v);
                    //stores particle in ParticleContainer
                    particles->addParticle(Particle(newX, newV, m));
                }
            }
        }
    }

    void generateSphere(std::shared_ptr<T> &particles, std::array<double, 3> center, int r, double m,
                        std::array<double, 3> v, double h) {
        double radius = (r - 1) * h;
        std::array<double, 3> newX{};
        for (int x = -r + 1; x < r; ++x) {
            newX[0] = center[0] + (x * h);
            for (int y = -r + 1; y < r; ++y) {
                newX[1] = center[1] + (y * h);
                for(int z=r +1 ; z< r; ++z){
                    newX[2] = center[2] + (z*h);
                    if(ArrayUtils::L2Norm(newX - center) > radius)
                        continue;
                    std::array<double, 3> newV = calculateV(v);
                    particles->addParticle(Particle(newX, newV, m));
                }
            }
        }
    }
};

