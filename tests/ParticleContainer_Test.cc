#include <gtest/gtest.h>
#include "Particle.h"
#include "container/ParticleContainer.h"
#include <vector>


/**
* @brief check if apply acts on particles in the container as expected
*/
TEST(ParticleContainerTest, AppyTest){
    ParticleContainer par{};


    par.addParticle( Particle ({0.,0.,0.},{0.,0., 0.}, 1.));
    par.addParticle(Particle ({1., 1. , 1.}, {1.5, 0., 0.}, 0.5));
    par.addParticle(Particle ({1., 0., 1.}, {1., 2., 0}, 0.01));

    par.apply([](Particle &p){
       p.setM(0);
    });

    const std::vector<Particle>& tmp = par.getParticles();


    EXPECT_DOUBLE_EQ(0., tmp[0].getM());
    EXPECT_DOUBLE_EQ(0., tmp[1].getM());
    EXPECT_DOUBLE_EQ(0., tmp[2].getM());

}



