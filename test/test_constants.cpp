#include <iostream>
#include <gtest/gtest.h>
#include <type_traits>

TEST(CppBasicConstants, integer_numerals) {
    auto dec = 75;
    auto oct = 0113;
    auto hex = 0x4b;
    auto bin = 0b0100'1011;
    // Assertion
    EXPECT_EQ(dec, oct);
    EXPECT_EQ(dec, hex);
    EXPECT_EQ(dec, bin);
}

TEST(CppBasicConstants, integer_numerals_suffix) {
    auto no_suffix = 75;
    auto suffix_u = 75u;
    auto suffix_l = 75l;
    auto suffix_ul = 75ul;
    auto suffix_lu = 75lu;
    // Assertion
    EXPECT_EQ(typeid(no_suffix), typeid(int));
    EXPECT_EQ(typeid(suffix_u), typeid(unsigned));
    EXPECT_EQ(typeid(suffix_l), typeid(long));
    EXPECT_EQ(typeid(suffix_ul), typeid(unsigned long));
    EXPECT_EQ(typeid(suffix_lu), typeid(suffix_ul));
}

TEST(CppBasicConstants, floating_point_numerals) {
    auto foo = 3.14159;
    auto bar = 314159e-5;
    auto suffix_f = 3.14159f;
    auto suffix_l = 3.14159l;
    // Assertion
    EXPECT_EQ(foo, bar);
    EXPECT_NEAR(foo, suffix_f, 0.1e-5); // float => double
    EXPECT_FLOAT_EQ(foo, suffix_f);     // double => float
    EXPECT_DOUBLE_EQ(foo, suffix_l);    // long double => double
    EXPECT_EQ(typeid(foo), typeid(double));
    EXPECT_EQ(typeid(suffix_f), typeid(float));
    EXPECT_EQ(typeid(suffix_l), typeid(long double));
}

TEST(CppBasicConstants, character_literals) {
    auto no_prefix = 'C';
    auto prefix_u = u'C';
    auto prefix_U = U'C';
    auto prefix_L = L'C';
    // Assertion
    EXPECT_EQ(typeid(no_prefix), typeid(char));
    EXPECT_EQ(typeid(prefix_u), typeid(char16_t));
    EXPECT_EQ(typeid(prefix_U), typeid(char32_t));
    EXPECT_EQ(typeid(prefix_L), typeid(wchar_t));
}

TEST(CppBasicConstants, string_literals) {
    auto no_prefix_str = "str" "ing" "\\n";
    auto prefix_R_str = R"xxx(string\n)xxx";    // == "string\\n"
    auto prefix_u8_str = u8"string\n";
    // Assertion
    std::string str{"string\\n"};
    EXPECT_TRUE(str.compare(no_prefix_str) == 0);
    EXPECT_TRUE(str.compare(prefix_R_str) == 0);
    EXPECT_FALSE(str.compare(prefix_u8_str) == 0);
}

TEST(CppBasicConstants, other_literals) {
    auto foo = true;
    auto bar = false;
    auto ptr = nullptr;
    // Assertion
    EXPECT_EQ(typeid(foo), typeid(bool));
    EXPECT_EQ(typeid(bar), typeid(bool));
    EXPECT_EQ(typeid(ptr), typeid(std::nullptr_t));
}