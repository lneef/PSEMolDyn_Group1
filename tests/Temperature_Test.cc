#include "gtest/gtest.h"
#include "tempCalculation/Thermostat.h"
#include "tempCalculation/Temperature.h"

TEST(TemperatureTest, CalcTest){
    Thermostat thermostat(2.0);
    std::shared_ptr<Thermostat> thermostat_pointer = std::make_shared<Thermostat>(thermostat);
    Temperature temperature;
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    par->addParticle(Particle ({0.,0.,0.},{2.,1., 0.}, 2.));
    temperature.calculateV(par,thermostat_pointer);

    EXPECT_EQ(thermostat.getTemp(), 5.);
}