#include "forceCalculation/LennardJones.h"
#include "gtest/gtest.h"
#include "MolSimTest.h"


/**
 * @brief test whether calculateF of Lennard Jones works a expected and old_f is updated as expected
 */
TEST(LennardJonesTest, CalcTest){
    ParticleContainer par{};

    par.addParticle(Particle ({0.,0.,0.},{0.,0., 0.}, 1.));
    par.addParticle(Particle ({1., 0. , 0.}, {1.5, 0., 0.}, 1.));

    std::array<double, 3> oldf{1.,1., 1.};
    par[0].setF(oldf);

    LennardJones lj{};

    lj.calculateF(par);
    const std::array<double, 3> f1{-120., 0. ,0.};
    const std::array<double, 3> f2{120, 0., 0.};
    MolSimTest::test_equ(par[0].getF(), f1);
    MolSimTest::test_equ(par[1].getF(), f2);
    MolSimTest::test_equ(par[0].getOldF(), oldf);


}