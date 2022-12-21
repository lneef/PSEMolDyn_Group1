#include "gtest/gtest.h"
#include "inputReader/xmlReader/XmlReader.h"

TEST(ReaderWriterTest, CheckpointTest) {
    std::string tes = "../tests/testinput/test2.xml";
    XMLReader::XmlReader xml{tes};
    std::shared_ptr<Simulation> sth1 = std::make_shared<Simulation>();
    std::shared_ptr<LinkedCellContainer> lc1 = std::make_shared<LinkedCellContainer>();
    xml.read(sth1, lc1);
    sth1->checkpoint("checkpoint");

    /*std::string tes2 = "../tests/testinput/test_checkpoint.xml";
    XMLReader::XmlReader xml2{tes2};
    std::shared_ptr<Simulation> sth2 = std::make_shared<Simulation>();
    std::shared_ptr<LinkedCellContainer> lc2 = std::make_shared<LinkedCellContainer>();
    xml2.read(sth2, lc2);

    std::vector<ParticleContainer> pc1 = lc1->getCells();
    std::vector<ParticleContainer> pc2 = lc2->getCells();
    std::vector<Particle> particles1;
    std::vector<Particle> particles2;


    for (int i = 0; i < pc1.size(); i++) {
        particles1 = pc1[i].getParticles();
        particles2 = pc2[i].getParticles();
        for (int z = 0; particles1.size(); z++) {
            std::array<double, 3> vel1 = particles1[z].getV();
            std::array<double, 3> vel2 = particles2[z].getV();
            EXPECT_DOUBLE_EQ(vel1[0], vel2[0]);
            EXPECT_DOUBLE_EQ(vel1[1], vel2[1]);
            EXPECT_DOUBLE_EQ(vel1[2], vel2[2]);
        }
    }*/
}