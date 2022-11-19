#include "gtest/gtest.h"
#include "MolSimLogger.h"




int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    MolSimLogger::init_test();
    return RUN_ALL_TESTS();
}