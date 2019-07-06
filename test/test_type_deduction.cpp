#include <iostream>
#include <gtest/gtest.h>
#include <type_traits>

template<typename T>
void printVariableType(T v, char const* name) {
    std::clog
        << typeid(T).name()
        << ", " << name
        << std::endl;
}
#define PRINT_VAR_TYPE(v)   printVariableType<decltype(v)>(v, #v)


TEST(TypeDeduction, auto_basic) {
    // deduction by literals
    auto integer_auto = 0;
    auto float_point_auto = 0.0;
    auto character_auto = 'C';
    auto string_auto = "string";
    // Assert
    EXPECT_EQ(typeid(integer_auto), typeid(int));
    EXPECT_EQ(typeid(float_point_auto), typeid(double));
    EXPECT_EQ(typeid(character_auto), typeid(char));
    EXPECT_EQ(typeid(string_auto), typeid(const char*));
}

TEST(TypeDeduction, decltype_basic) {
    auto string_auto = "string";
    // deduction by literals
    decltype(0) integer_decltype;
    decltype(0.0) float_point_decltype;
    decltype('C') character_decltype;
    decltype("string") string_decltype = "STRING";   // compile error without initialization
    // dedection by variable
    decltype(string_auto) deduced_decltype;
    PRINT_VAR_TYPE(string_decltype);
    PRINT_VAR_TYPE(string_auto);
    // Assert
    EXPECT_EQ(typeid(integer_decltype), typeid(int));
    EXPECT_EQ(typeid(float_point_decltype), typeid(double));
    EXPECT_EQ(typeid(character_decltype), typeid(char));
    EXPECT_EQ(typeid(string_decltype), typeid(const char[sizeof("STRING")]));
}
