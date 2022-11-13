#include <gtest/gtest.h>
#include "../src/Particle.h"
#include "../src/ParticleContainer.h"
#include "../src/MolSimLogger.h"
#include <vector>
#include "gtest/gtest.h"

/**
* @brief check whether iterator of ParticleContainer enables iteration over all stored particles
*/
TEST(ParticleContainerTest, IteratorTest){
    ParticleContainer par{};

    par.addParticle( Particle ({0.,0.,0.},{0.,0., 0.}, 1.));
    par.addParticle(Particle ({1., 1. , 1.}, {1.5, 0., 0.}, 0.5));
    par.addParticle(Particle ({1., 0., 1.}, {1., 2., 0}, 0.01));

    const std::vector<Particle>& tmp = par.getParticles();

    ParticleContainer::iterator it = par.begin();

    EXPECT_EQ(&(*it++), &tmp[0]);
    EXPECT_EQ(&(*it++), &tmp[1]);
    EXPECT_EQ(&(*it++), &tmp[2]);


}

