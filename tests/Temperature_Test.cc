#include "gtest/gtest.h"
#include "tempCalculation/Thermostat.h"

TEST(TemperatureTest, CalcTest){
    std::shared_ptr<Thermostat> thermostat_pointer = std::make_shared<Thermostat>(2.0);
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    par->addParticle(Particle ({0.,0.,0.},{2.,1., 0.}, 2.));
    thermostat_pointer->calculateV(par);

    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 5.);
}