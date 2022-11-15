#include "gtest/gtest.h"
#include "MolSimLogger.h"




int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    MolSimLogger::init();
    return RUN_ALL_TESTS();
}