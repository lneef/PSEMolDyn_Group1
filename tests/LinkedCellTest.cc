
#include "gtest/gtest.h"
#include "container/LinkedCellContainer.h"
#include "inputReader/CuboidGenerator.h"


TEST(LinkedCellTest, AddTest){
    CuboidGenerator<LinkedCellContainer> cub{};
    std::vector<ParticleList> list{2*2};
    std::array<int, 3> mesh = {2, 2, 1,};
    std::unique_ptr<LinkedCellContainer> test = std::make_unique<LinkedCellContainer>(mesh , 1., list);
    cub.generateCuboid(test, {0, 0, 0}, {2, 2, 1}, 1, 0., {0., 0., 0.});

    std::vector<ParticleList> celllist = test -> getCells();

    EXPECT_EQ(celllist[0].size(), 1);
    EXPECT_EQ(celllist[1].size(), 1);
    EXPECT_EQ(celllist[2].size(), 1);
    EXPECT_EQ(celllist[3].size(), 1);
}

TEST(LinkedCellTest, AppTest){
    CuboidGenerator<LinkedCellContainer> cub{};
    std::vector<ParticleList> list{3*3};
    std::array<int, 3> mesh = {3, 3, 1,};
    std::unique_ptr<LinkedCellContainer> test = std::make_unique<LinkedCellContainer>(mesh , 1., list);
    cub.generateCuboid(test, {0, 0, 0}, {3, 3, 1}, 1, 0., {0., 0., 0.});
    test->applyF([](Particle& p1, Particle &p2){
       std::array<double, 3> add={1., 0., 0.};
       p1.setF(p1.getF() + add);
       p2.setF(p2.getF() + add);
    });
    std::vector<ParticleList> celllist = test -> getCells();
    auto it1 = celllist[0].begin();
    auto it4 = celllist[4].begin();
    auto it7 = celllist[7].begin();


    EXPECT_EQ(it1->getF()[0], 2);
    EXPECT_EQ(it7->getF()[0], 3);
    EXPECT_EQ(it4->getF()[0], 4);
}