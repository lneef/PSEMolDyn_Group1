#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "inputReader/Cuboid_file.h"


TEST(CuboidTest, RightTest){
    inputReader::Cuboid_file file("../tests/testinput/test.txt");
    ParticleContainer par{};
    file.read(par);
    std::array<double, 3> pos{};
    EXPECT_EQ(par[0].getX(),pos);
    pos={0., 1., 0.};
    EXPECT_EQ(par[1].getX(), pos);
    pos={1., 0., 0.};
    EXPECT_EQ(par[2].getX(), pos);
    pos={1., 1., 0.};
    EXPECT_EQ(par[3].getX(), pos);
}