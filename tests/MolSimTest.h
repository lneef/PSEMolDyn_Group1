//
// Created by lukas on 15.11.22.
//

#pragma once

/**
 * @brief This namespace provides functionality used by several tests
 */
namespace MolSimTest {
    /**
     * @brief checks two double array for value equality
     * @param vec1 first array under test
     * @param vec2 second array under test
     */
    void test_equ(const std::array<double, 3> &vec1, const std::array<double, 3> &vec2);
};



