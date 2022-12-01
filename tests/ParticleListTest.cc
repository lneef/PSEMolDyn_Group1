#include "gtest/gtest.h"
#include "container/Container.h"
#include "container/ParticleList.h"
#include "utils/ArrayUtils.h"

TEST(ParticleListTest, ApplyF){
    ParticleList par{};
    par.addParticle( Particle ({0.,0.,0.},{0.,0., 0.}, 1.));
    par.addParticle(Particle ({1., 1. , 1.}, {1.5, 0., 0.}, 0.5));
    par.addParticle(Particle ({1., 0., 1.}, {1., 2., 0}, 0.01));

    par.applyF([](Particle& p1, Particle& p2){
        std::array<double, 3> add={1., 0., 0.};
        p1.setF(p1.getF() + add);
        p2.setF(p2.getF() + add);
    });

    auto it = par.begin();

    EXPECT_DOUBLE_EQ((it++)->getF()[0], 2);
    EXPECT_DOUBLE_EQ((it++)->getF()[0], 2);
    EXPECT_DOUBLE_EQ((it++)->getF()[0], 2);
}