#include <gmock/gmock-matchers.h>
#include "forceCalculation/LennardJones.h"
#include "gtest/gtest.h"


/**
 * @brief test whether calculateF of Lennard Jones works a expected and old_f is updated as expected
 */
TEST(LennardJonesTest, CalcTest){
    std::unique_ptr<Container> par = std::make_unique<ParticleContainer>();
    par->addParticle(Particle ({0.,0.,0.},{0.,0., 0.}, 1.));
    par->addParticle(Particle ({1., 0. , 0.}, {1.5, 0., 0.}, 1.));

    std::array<double, 3> oldf{1.,1., 1.};
    auto &p = dynamic_cast<ParticleContainer&>(*par);
    p[0].setF(oldf);

    LennardJones lj{};

    lj.calculateF(par);
    const std::array<double, 3> f1{-120., 0. ,0.};
    const std::array<double, 3> f2{120, 0., 0.};

    EXPECT_THAT(p[0].getF(), testing::Pointwise(testing::DoubleEq(),f1));
    EXPECT_THAT(p[1].getF(), testing::Pointwise(testing::DoubleEq(), f2));
    EXPECT_THAT(p[0].getOldF(), testing::Pointwise(testing::DoubleEq(), oldf));


}