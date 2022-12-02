
#include "gtest/gtest.h"
#include "container/LinkedCellContainer.h"
#include "inputReader/CuboidGenerator.h"


class LinkedCellTest : public testing::Test {
protected:
    std::shared_ptr<LinkedCellContainer> test;

    void SetUp() override {
        CuboidGenerator<LinkedCellContainer> cub{};
        test = std::make_shared<LinkedCellContainer>();
        std::array<double, 3> domain{3., 3., 0.5};
        test->setDomain(domain);
        test->setSize(1., domain);
        cub.generateCuboid(test, {0.5, 0.5, 0}, {3, 3, 1}, .5, 0., {0., 0., 0.});
    }

    void TearDown() override {

    }
};

TEST_F(LinkedCellTest, AddTest) {

    std::vector<ParticleContainer> celllist = test->getCells();

    EXPECT_EQ(test->size(), 9);
    EXPECT_EQ(celllist[0].size(), 1);
    EXPECT_EQ(celllist[1].size(), 2);
    EXPECT_EQ(celllist[2].size(), 0);
    EXPECT_EQ(celllist[3].size(), 2);
    EXPECT_EQ(celllist[4].size(), 4);

}

TEST_F(LinkedCellTest, AppTest) {
    test->applyF([](Particle &p1, Particle &p2) {
        std::array<double, 3> add = {1., 0., 0.};
        p1.setF(p1.getF() + add);
        p2.setF(p2.getF() + add);
    });
    std::vector<ParticleContainer> celllist = test->getCells();
    auto it1 = celllist[0].begin();
    auto it4 = celllist[4].begin();


    EXPECT_DOUBLE_EQ(it1->getF()[0], 8);
    EXPECT_DOUBLE_EQ(it4->getF()[0], 8);
}