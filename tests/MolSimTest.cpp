//
// Created by lukas on 15.11.22.
//
#include "gtest/gtest.h"
#include "MolSimTest.h"
namespace MolSimTest {
    void test_equ(const std::array<double, 3> &vec1, const std::array<double, 3> &vec2) {
        for (int i = 0; i < 3; ++i) {
            EXPECT_DOUBLE_EQ(vec1[i], vec2[i]);
        }
    }
}