#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "forceCalculation/Force.h"
#include "outputWriter/FileWriter.h"
#include "Simulation.h"


/**
 * @brief mocks the class Force
 */
class ForceMock : virtual public Force{
public:
    MOCK_METHOD(void , calculateF, (std::shared_ptr<Container> &particles), (override));
};

/**
 * @brief mocks the class FileWriter
 */
class OutMock : public outputWriter::FileWriter{
public:
    MOCK_METHOD(void, plotParticles, (std::shared_ptr<Container> &particles, const std::string &filename, int iteration) , (override));

};
/**
 * @brief test that calculation of f and output is called as often as expected
 */
TEST(SimulationTest, CallNumber){
    std::shared_ptr<Container> par = std::make_shared<ParticleContainer>();
    std::unique_ptr<Force> force = std::make_unique<ForceMock>();
    std::unique_ptr<outputWriter::FileWriter> writer = std::make_unique<OutMock>();
    EXPECT_CALL(dynamic_cast<ForceMock&>(*force), calculateF).Times(12);
    EXPECT_CALL(dynamic_cast<OutMock&>(*writer), plotParticles).Times(1);
    Simulation sim(par, 1, 11, writer, force);
    sim.run();
}