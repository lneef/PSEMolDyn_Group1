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
public:
    MOCK_METHOD(void, plotParticles, (ParticleContainer &particles, const std::string &filename, int iteration) , (override));

};

TEST(SimulationTest, CallNumber){
    ParticleContainer par{};
    testing::Sequence s1, s2;
    std::unique_ptr<Force> force = std::make_unique<ForceMock>();
    std::unique_ptr<outputWriter::FileWriter> writer = std::make_unique<OutMock>();
    EXPECT_CALL(dynamic_cast<ForceMock&>(*force), calculateF).Times(12);
    EXPECT_CALL(dynamic_cast<OutMock&>(*writer), plotParticles).Times(1);
    Simulation sim(par, 1, 11, writer, force);
    sim.run();
}