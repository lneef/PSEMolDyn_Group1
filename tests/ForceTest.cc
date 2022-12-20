//
// Created by dominik on 16.11.22.
//
#include <gtest/gtest.h>
#include "../src/forceCalculation/LennardJones.h"
#include "forceCalculation/LJGravitation.h"
#include <vector>
#include <gmock/gmock-matchers.h>
#include "MolSimLogger.h"

/**
 * @brief test whether calculateF of Lennard Jones works a expected with more than 2 particles
 */

class ForceTest : public testing::Test {
protected:
    std::shared_ptr<Container> par;
    void SetUp() override{
        par = std::make_shared<ParticleContainer>();
        par->addParticle( Particle({0., 0., 0.}, {0., 0., 0.}, 1.));
        par->addParticle(Particle({1., 1., 0.}, {0., 0., 0.}, 1.));
        par->addParticle(Particle({1., 0., 0.}, {0., 0., 0}, 1.));

    }
    void TearDown() override {

    }
};

/**
 * @brief test Lennard Jones force calculation routine with a more complex example
 */
TEST_F(ForceTest, CalcTest){
    LennardJones lj;
    lj.calculateF(par);

    std::array<double, 3> f1 = {-114.375,5.625,0};
    std::array<double, 3> f2 = {-5.625,114.375,0};
    std::array<double, 3> f3 = {120,-120,0};
    auto &p = dynamic_cast<ParticleContainer&>(*par);
    MolSimLogger::logInfo("Force: {}", p[2].getF()[0], p[2].getF()[1], p[2].getF()[2]);


    EXPECT_THAT(p[0].getF(), testing::Pointwise(testing::DoubleEq(),f1));
    EXPECT_THAT(p[1].getF(), testing::Pointwise(testing::DoubleEq(), f2));
    EXPECT_THAT(p[2].getF(), testing::Pointwise(testing::DoubleEq(), f3));
}

/**
 * @brief test LJGravitation force calculation routine
 */
TEST_F(ForceTest, GravTest){
    LJGravitation ljg{-10};
    ljg.calculateF(par);

    std::array<double, 3> f1 = {-114.375,-4.375,0};
    std::array<double, 3> f2 = {-5.625,104.375,0};
    std::array<double, 3> f3 = {120,-130,0};

    auto &p = dynamic_cast<ParticleContainer&>(*par);
    EXPECT_THAT(p[0].getF(), testing::Pointwise(testing::DoubleEq(),f1));
    EXPECT_THAT(p[1].getF(), testing::Pointwise(testing::DoubleEq(), f2));
    EXPECT_THAT(p[2].getF(), testing::Pointwise(testing::DoubleEq(), f3));


}
