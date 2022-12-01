//
// Created by dominik on 16.11.22.
//
#include <gtest/gtest.h>
#include "../src/forceCalculation/LennardJones.h"
#include <vector>
#include <gmock/gmock-matchers.h>

/**
 * @brief test whether calculateF of Lennard Jones works a expected with more than 2 particles
 */
TEST(LennardJonesTest, CalcTest2){
    LennardJones lj;
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    par->addParticle( Particle({0., 0., 0.}, {0., 0., 0.}, 0.));
    par->addParticle(Particle({1., 1., 0.}, {0., 0., 0.}, 0.));
    par->addParticle(Particle({1., 0., 0.}, {0., 0., 0}, 0.));

    std::array<double, 3> f1 = {-114.375,5.625,0};
    std::array<double, 3> f2 = {-5.625,114.375,0};
    std::array<double, 3> f3 = {120,-120,0};

    lj.calculateF(par);

    auto &p = dynamic_cast<ParticleContainer&>(*par);
    EXPECT_THAT(p[0].getF(), testing::Pointwise(testing::DoubleEq(),f1));
    EXPECT_THAT(p[1].getF(), testing::Pointwise(testing::DoubleEq(), f2));
    EXPECT_THAT(p[2].getF(), testing::Pointwise(testing::DoubleEq(), f3));
}