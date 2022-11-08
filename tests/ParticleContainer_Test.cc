#include <gtest/gtest.h>
#include "../src/Particle.h"
#include "../src/ParticleContainer.h"
#include <vector>

/**
* @brief check whether iterator of ParticleContainer enables iteration over all stored particles
*/
TEST(ParticleContainerTest, IteratorTest){
    ParticleContainer par{};

    Particle p1({0.,0.,0.},{0.,0., 0.}, 1.);
    Particle p2({1., 1. , 1.}, {1.5, 0., 0.}, 0.5);
    Particle p3({1., 0., 1.}, {1., 2., 0}, 0.01); 
    
    par.addParticle(p1);
    par.addParticle(p2);
    par.addParticle(p3);

    const std::vector<Particle>& tmp = par.getParticles();
    
    ParticleContainer::iterator it = par.begin();

    EXPECT_EQ(&(*it++), &tmp[0]);
    EXPECT_EQ(&(*it++), &tmp[1]);
    EXPECT_EQ(&(*it++), &tmp[2]);
    

}

