#include "gtest/gtest.h"
#include "inputReader/xmlReader/XmlReader.h"

/**
 * @brief tests if XML-Parser works correctly
 */
TEST(ParserTestSite, Basic) {
    std::string tes = "../tests/testinput/test.xml";
    XMLReader::XmlReader xml{tes};
    std::shared_ptr<Simulation> sth = std::make_shared<Simulation>();
    std::shared_ptr<LinkedCellContainer> lc = std::make_shared<LinkedCellContainer>();
    xml.read(sth, lc);
    auto & force = sth->getForce();

    auto &particles = lc->getCells();

    EXPECT_EQ(lc->size(), 9);
    EXPECT_EQ(typeid(*force), typeid(LJGravitation));
    EXPECT_EQ(particles[6].size(), 4);
    EXPECT_EQ(particles[7].size(), 2);
    EXPECT_EQ(particles[11].size(), 2);
    EXPECT_EQ(particles[12].size(), 1);


}