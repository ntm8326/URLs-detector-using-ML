//
// Created by AD on 7/30/2026.
//
#include <gtest/gtest.h>
#include "url_features/SpecialChar.hpp"
TEST(DotCountTest, RealURL_NumberOfDot) {
    EXPECT_EQ(SpecialChar::dot_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 2);
}

TEST(HyphenCountTest, RealURL_NumberOfHyphen) {
    EXPECT_EQ(SpecialChar::hyphen_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 4);
}

TEST(HashCountTest, RealURL_NumberOfHash) {
    EXPECT_EQ(SpecialChar::hash_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 0);
}

TEST(PercentCountTest, RealURL_NumberOfPercent) {
    EXPECT_EQ(SpecialChar::percent_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 0);
}

TEST(SlashCountTest, RealURL_NumberOfSlash) {
    EXPECT_EQ(SpecialChar::slash_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 3);
}

TEST(AtSignCountTest, RealURL_NumberOfAtSign) {
    EXPECT_EQ(SpecialChar::at_sign_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 0);
}

TEST(AmpersandCountTest, RealURL_NumberOfAmpersand) {
    EXPECT_EQ(SpecialChar::ampersand_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 0);
}

TEST(EqualCountTest, RealURL_NumberOfEqual) {
    EXPECT_EQ(SpecialChar::equal_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 1);
}

TEST(QuestionCountTest, RealURL_NumberOfQuestion) {
    EXPECT_EQ(SpecialChar::question_count("https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c"), 1);
}