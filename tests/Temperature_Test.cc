#include "gtest/gtest.h"
#include "tempCalculation/Thermostat.h"
#include "tempCalculation/Temperature.h"

TEST(TemperatureTest, CalcTest){
    std::shared_ptr<Thermostat> thermostat_pointer = std::make_shared<Thermostat>(2.0);
    Temperature temperature;
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    par->addParticle(Particle ({0.,0.,0.},{2.,1., 0.}, 2.));
    temperature.calculateV(par,thermostat_pointer);

    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 5.);
}