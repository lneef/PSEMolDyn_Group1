//
// Created by lukas on 04.12.22.
//
#pragma once


#include <array>
#include "utils/ArrayUtils.h"
#include "forceCalculation/LennardJones.h"

/**
 * @brief implements the necessary functionality for the reflecting boundary condition
 */
class Reflecting{
private:
    /**
     * @brief indicator array for which boundary the condition should be applied
     */
    std::array<double, 3> indicator;

    /**
     * @brief coordinate of the boundary
     */
    double border;

    /**
     * @brief calclates the difference between a particle and the boundary
     * @param p particle for which the distance is calculated
     * @return distance to boundary
     */
    double difference(const Particle& p);

    /**
     * @brief critical distance to boundary, when below the repulsing force using the counter particle is calculated
     */
    static double critical;
public:

    /**
     * @brief constructor of the boundary condition
     * @param indicator_arg initialized the indicator
     * @param border coordinate of the boundary
     */
    Reflecting(std::array<double, 3>& indicator_arg, double border);

    /**
     * @brief checks if distance between boundary and particle is below critical
     * @param p particle to which the boundary condition is applied
     * @return true is distance is below critical
     */
    bool check(const Particle& p);

    /**
     * @brief initializes the field critical
     * @param sigma zero crossing value for the liquid
     */
    static void init_bound(double sigma);

    /**
     * @brief applies the reflecting boundary condition by calculating the force between the particle and its counter
     * @tparam T function taking two lvalue refernces to particles
     * @param p Particle inside a boundary cell
     * @param fun function to calculate the force
     */
    template<class T>void apply(Particle & p, T fun){
        std::array<double, 3> to_add{};

        to_add = difference(p) * indicator;

        Particle p_counter(p.getX() + 2 * to_add, p.getV(),p.getM());

        fun(p, p_counter);

    }

};


