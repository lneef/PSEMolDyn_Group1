#include "inputReader/CuboidGenerator.h"
#include "gtest/gtest.h"

/**
 * @brief test if right number of particles is generated
 */
TEST(SphereTest, TwoinEach) {
    CuboidGenerator<ParticleContainer> gen{};
    std::shared_ptr<ParticleContainer> par = std::make_shared<ParticleContainer>();
    std::array<double, 3> center{0., 0., 0.};
    gen.generateSphere(par,center , 3, 1.0, center, 1.0);
    EXPECT_EQ(par->size(), 93);
}