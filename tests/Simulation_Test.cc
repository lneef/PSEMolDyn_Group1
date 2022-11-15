#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "forceCalculation/Force.h"
#include "outputWriter/FileWriter.h"
#include "Simulation.h"

class ForceMock : virtual public Force{
public:
    MOCK_METHOD(void , calculateF, (ParticleContainer &particles), (override));

};

class OutMock : public outputWriter::FileWriter{
    MOCK_METHOD(void, plotParticles, (ParticleContainer &particles, const std::string &filename, int iteration) , (override));

};

TEST(SimulationTest, CallNumber){
    ParticleContainer par{};
    std::unique_ptr<Force> force = std::make_unique<ForceMock>();
    EXPECT_CALL(dynamic_cast<ForceMock&>(*force), calculateF).Times(12);
    Simulation sim(par, 1, 11, std::make_unique<OutMock>(), force);
    sim.run();
}