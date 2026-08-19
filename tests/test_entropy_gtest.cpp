//
// Created by AD on 7/28/2026.
//

#include <gtest/gtest.h>
#include "url_features/StaticFeatures/Entropy.hpp"

TEST(EntropyTest, EmptyString_ReturnsZero) {
    EXPECT_DOUBLE_EQ(Entropy::Shannon_entropy(""), 0.0);
}

TEST(EntropyTest, SingleCharRepeated_ReturnsZero) {
    EXPECT_DOUBLE_EQ(Entropy::Shannon_entropy("aaaaaaaaaaaaaaaaaaaaaaaaaaaa"), 0.0);
}

TEST(EntropyTest, AllDistinct_ReturnsLog2N) {
    EXPECT_NEAR(Entropy::Shannon_entropy("abcd"), 2.0, 0.001);
}

TEST(EntropyTest, TwoCharTypes_ReturnsOne) {
    EXPECT_NEAR(Entropy::Shannon_entropy("aabb"), 1.0, 0.001);
}

TEST(EntropyTest, RealURL_PositiveEntropy) {
    EXPECT_GT(Entropy::Shannon_entropy("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 0.0);
}

TEST(EntropyTest, RealDomain_PositiveEntropy) {
    EXPECT_GT(Entropy::Shannon_entropy("paypal"), 0.0);
}


