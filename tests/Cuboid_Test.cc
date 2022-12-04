#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "inputReader/Cuboid_file.h"
/**
 * @brief test if particles generated form read cuboid are at the right position
 */
TEST(CuboidTest, RightTest) {

    inputReader::Cuboid_file file("../tests/testinput/test.txt");
    std::shared_ptr<ParticleContainer> par = std::make_shared<ParticleContainer>();
    file.read(par);
    std::array<double, 3> pos{};
    EXPECT_THAT((*par)[0].getX(), testing::Pointwise(testing::DoubleEq(), pos));
    pos = {0., 1., 0.};
    EXPECT_THAT((*par)[1].getX(), testing::Pointwise(testing::DoubleEq(), pos));
    pos = {1., 0., 0.};
    EXPECT_THAT((*par)[2].getX(), testing::Pointwise(testing::DoubleEq(), pos));
    pos = {1., 1., 0.};
    EXPECT_THAT((*par)[3].getX(), testing::Pointwise(testing::DoubleEq(), pos));
}