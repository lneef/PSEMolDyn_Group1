#include "gtest/gtest.h"
#include "tempCalculation/Thermostat.h"

TEST(TemperatureTest, CalcTest){
    std::shared_ptr<Thermostat> thermostat_pointer = std::make_shared<Thermostat>(2.0);
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    par->addParticle(Particle ({0.,0.,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({0.5,0.,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({1.,0.,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({0.,0.5,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({0.5,0.5,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({1.,0.5,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({0.,1.,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({0.5,1.,0.},{3.,3., 0.}, 2.));
    par->addParticle(Particle ({1.,1.,0.},{3.,3., 0.}, 2.));
    thermostat_pointer->calculateV(par);

    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 18.);
}