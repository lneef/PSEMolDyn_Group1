#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "inputReader/Cuboid_file.h"
#include "MolSimTest.h"

/**
 * @brief test if particles generated form read cuboid are at the right position
 */
TEST(CuboidTest, RightTest){
    inputReader::Cuboid_file file("../tests/testinput/test.txt");
    ParticleContainer par{};
    file.read(par);
    std::array<double, 3> pos{};
    MolSimTest::test_equ(par[0].getX(),pos);
    pos={0., 1., 0.};
    MolSimTest::test_equ(par[1].getX(), pos);
    pos={1., 0., 0.};
    MolSimTest::test_equ(par[2].getX(), pos);
    pos={1., 1., 0.};
    MolSimTest::test_equ(par[3].getX(), pos);
}