//
// Created by lukas on 04.12.22.
//
#pragma once


#include <array>
#include "utils/ArrayUtils.h"
#include "forceCalculation/LennardJones.h"

class Reflecting{
private:
    std::array<double, 3> indicator;
    double border;
    double difference(const Particle& p);
    static double critical;
public:

    ~Reflecting();
    Reflecting(std::array<double, 3>& indicator_arg, double border);

    bool check(const Particle& p);
    static void init_bound(double sigma);

    template<class T>void apply(Particle & p, T fun){
        std::array<double, 3> to_add{};

        to_add = difference(p) * indicator;

        Particle p_counter(p.getX() + 2 * to_add, p.getV(),p.getM());

        fun(p, p_counter);

    }

};



