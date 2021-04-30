/**
 * @file tests.cpp
 * @author Christian Bruccoleri (cbruccoleri@gmail.com)
 * @brief A simple test suite as a template for other projects.
 * 
 * The code shown here does not use test fixtures. Refer to GTest documentation
 * for more advanced usage and many more test macros.
 * 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 * License: MIT License.
 * 
 */
#include "somelib.h"
#include <gtest/gtest.h>


TEST(gcdExampleTest, testKnownOutput) 
{
    EXPECT_EQ(gcd(6, 4), 2);
    EXPECT_EQ(gcd(4, 7), 1);
    EXPECT_EQ(gcd(12, 0), 12);
    EXPECT_EQ(gcd(0, 23), 23);
    EXPECT_EQ(gcd(0, 0), 0);
}



TEST(gcdExampleTest, testNegativeInput)
{
    EXPECT_EQ(gcd(-6, 4), -2);
    EXPECT_EQ(gcd(18, -30), 6);
    EXPECT_EQ(gcd(-18, -30), -6);
}

// Note: a main() is not needed here because GTest provides a default one.