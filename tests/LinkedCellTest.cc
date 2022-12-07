
#include "gtest/gtest.h"
#include "container/LinkedCellContainer.h"
#include "inputReader/CuboidGenerator.h"
#include "Simulation.h"


class LinkedCellTest : public testing::Test {
protected:
    std::shared_ptr<LinkedCellContainer> test;

    void SetUp() override {
        CuboidGenerator<LinkedCellContainer> cub{};
        test = std::make_shared<LinkedCellContainer>();
        std::array<double, 3> domain{3., 3., 0.5};
        test->setDomain(domain);
        test->setSize(1., domain, 2);
        cub.generateCuboid(test, {.75, .75, 0}, {3, 3, 1}, .75, 1.0, {0., 1, 0.});
    }

    void TearDown() override {

    }
};

/**
 * @brief tests if particles are added to the right cells
 */
TEST_F(LinkedCellTest, AddTest) {

    std::vector<ParticleContainer> celllist = test->getCells();

    EXPECT_EQ(test->size(), 9);
    EXPECT_EQ(celllist[6].size(), 1);
    EXPECT_EQ(celllist[7].size(), 1);
    EXPECT_EQ(celllist[11].size(), 1);
    EXPECT_EQ(celllist[12].size(), 1);


}

TEST_F(LinkedCellTest, BoundaryHalo_Test){
     EXPECT_EQ(test->getBoundary().size(), 9);
    EXPECT_EQ(test->getHalo().size(), 9);
}

/**
 * @brief tests if force calculation function is applied to all particles correctly
 */
TEST_F(LinkedCellTest, AppTest) {
    test->applyF([](Particle &p1, Particle &p2) {
        std::array<double, 3> add = {1., 0., 0.};
        p1.setF(p1.getF() + add);
        p2.setF(p2.getF() + add);
    });
    std::vector<ParticleContainer> celllist = test->getCells();
    auto it1 = celllist[6].begin();
    auto it2 = celllist[11].begin();
    auto it4 = celllist[12].begin();
    auto it3 = celllist[17].begin();
    
    EXPECT_DOUBLE_EQ((*it1).getF()[0], 3);
    EXPECT_DOUBLE_EQ(it2->getF()[0], 5);
    EXPECT_DOUBLE_EQ((*it4).getF()[0], 8);
    EXPECT_DOUBLE_EQ(it3->getF()[0], 5);

}

/**
 * @brief tests if reflecting boundary condition is applied to all particles
 */
TEST_F(LinkedCellTest, ReflectingBoundary){
    Reflecting::init_bound(2);
    std::array<double ,3 > arr{1., 0, 0};
    test->addReflecting(Reflecting(arr, 0));
    test->addReflecting(Reflecting(arr, 3.));
    test->applyF([](Particle &p1, Particle &p2) {
        std::array<double, 3> add = {1., 0., 0.};
        p1.setF(p1.getF() + add);
        p2.setF(p2.getF() + add);
    });
    std::vector<ParticleContainer> celllist = test->getCells();
    auto it1 = celllist[6].begin();
    auto it2 = celllist[8].begin();
    auto it4 = celllist[11].begin();


    EXPECT_DOUBLE_EQ((*it1).getF()[0], 4);
    EXPECT_DOUBLE_EQ((*it4).getF()[0], 6);
    EXPECT_DOUBLE_EQ((*it2).getF()[0], 4);
}

/**
 * @brief test if particles leaving the domain are deleted
 */
TEST_F(LinkedCellTest, Outflow){
    Simulation sim(1, 1);
    sim.setParticle(test);
    sim.calculateX();
    auto celllist = test-> getCells();
    EXPECT_EQ(test->size(), 6);
    EXPECT_EQ(celllist[11].size(), 1);
    EXPECT_EQ(celllist[7].size(), 0);
    EXPECT_EQ(celllist[18].size(), 1);


}

/**
 * @brief test applyF with several particles per cell
 */
TEST(LinkedCellTest_Outflow_Test, AppTest1){
    CuboidGenerator<LinkedCellContainer> cub{};
    std::shared_ptr<LinkedCellContainer> test1 = std::make_shared<LinkedCellContainer>();
    std::array<double, 3> domain{3., 3., 0.5};
    test1->setDomain(domain);
    test1->setSize(1., domain, 2);
    cub.generateCuboid(test1, {.75, .75, 0}, {3, 3, 1}, .5, 1.0, {0., 1, 0.});

    test1->applyF([](Particle &p1, Particle &p2) {
        std::array<double, 3> add = {1., 0., 0.};
        p1.setF(p1.getF() + add);
        p2.setF(p2.getF() + add);
    });
    std::vector<ParticleContainer> celllist = test1->getCells();
    auto it1 = celllist[6].begin();
    auto it4 = celllist[12].begin();

    EXPECT_DOUBLE_EQ(it1->getF()[0], 8);
    EXPECT_DOUBLE_EQ(it4->getF()[0], 8);
}