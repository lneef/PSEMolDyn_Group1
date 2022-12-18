#include "gtest/gtest.h"
#include "utils//Thermostat.h"
#include "container/ParticleContainer.h"
#include "inputReader/CuboidGenerator.h"
#include "container/LinkedCellContainer.h"

TEST(TemperatureTest, CalcTest){
    std::shared_ptr<Thermostat> thermostat_pointer = std::make_shared<Thermostat>(2.0);
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    par->addParticle(Particle ({0.,0.,0.},{2.,1., 0.}, 2.));
    thermostat_pointer->applyThermostat(par);

    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 5.);
}
class TempTest : public testing::Test{
protected:
    std::shared_ptr<Thermostat> thermostat_pointer;
    std::shared_ptr<Container> test;

    void SetUp() override{
        CuboidGenerator<LinkedCellContainer> cub{};
        thermostat_pointer = std::make_shared<Thermostat>(2.0);

        std::shared_ptr<LinkedCellContainer> par = std::make_shared<LinkedCellContainer>();
        cub.generateCuboidNoBrownian(par, {.55, .55, 0}, {3, 3, 1}, {4, 6, 0}, 1,  1.0, 1);
        std::array<double, 3> domain{3., 3., 0.5};
        par->setDomain(domain);
        par->setSize(1., domain, 2);

        test = par;

        cub.generateCuboidNoBrownian(par, {0.,0.,0.}, {3, 3 , 1},{4, 6, 0}, 2, 1.0);
    }

    void TearDown() override{

    }

};

TEST_F(TempTest, Heating_Test){
    thermostat_pointer->setDelta(5.0);
    thermostat_pointer->setTarget(31);
    thermostat_pointer->applyThermostat(test);
    thermostat_pointer->measureTemp(test);
    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 31);
}

TEST_F(TempTest, Keeping_Test){
    thermostat_pointer->setDelta(1.0);
    thermostat_pointer->setTarget(26);
    thermostat_pointer->applyThermostat(test);
    thermostat_pointer->measureTemp(test);
    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 26);
}

TEST_F(TempTest, Cooling_Test){
    thermostat_pointer->setDelta(2.0);
    thermostat_pointer->setTarget(20);
    thermostat_pointer->applyThermostat(test);
    thermostat_pointer->applyThermostat(test);
    thermostat_pointer->applyThermostat(test);
    thermostat_pointer->measureTemp(test);
    EXPECT_DOUBLE_EQ(thermostat_pointer->getTemp(), 20);
}


