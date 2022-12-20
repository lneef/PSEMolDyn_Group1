#include "inputReader/ParticleGenerator.h"
#include "gtest/gtest.h"

/**
 * @brief test if right number of particles is generated
 */
TEST(SphereTest, TwoinEach) {
    ParticleGenerator<ParticleContainer> gen{};
    std::shared_ptr<ParticleContainer> par = std::make_shared<ParticleContainer>();
    std::array<double, 3> center{0., 0., 0.};
    std::array<double, 3> vel{0., 0., 0.};
    gen.generateSphere(par,center , 4, 1.0, vel, 1.0);
    EXPECT_EQ(par->size(), 45);
}
