#include <iostream>
#include <gtest/gtest.h>
#include <type_traits>

template<typename T>
void printTypeName(char const* name) {
    std::clog
        << typeid(T).name()
        << ", " << name
        << std::endl;
}
#define PRINT_TYPE_NAME(T)  printTypeName<T>(#T)

template<typename T>
void printTypeSize(char const* name) {
    std::clog
        << typeid(T).name()
        << ", sizeof(" << name << ") = " << sizeof(T)
        << std::endl;
}
#define PRINT_TYPE_SIZE(T)   printTypeSize<T>(#T)


TEST(CppBasicTypes, characters) {
    PRINT_TYPE_SIZE(char);
    PRINT_TYPE_SIZE(char16_t);
    PRINT_TYPE_SIZE(char32_t);
    PRINT_TYPE_SIZE(wchar_t);
    // Assert
    EXPECT_EQ(sizeof(char), 1);
    EXPECT_GE(sizeof(char16_t), 2);
    EXPECT_GE(sizeof(char32_t), 4);
    EXPECT_EQ(sizeof(wchar_t), sizeof(char32_t));
}

TEST(CppBasicTypes, integers) {
    PRINT_TYPE_SIZE(signed char);
    PRINT_TYPE_SIZE(short);
    PRINT_TYPE_SIZE(int);
    PRINT_TYPE_SIZE(long);
    PRINT_TYPE_SIZE(long long);
    // Assert
    EXPECT_GE(sizeof(signed char), 1);
    EXPECT_GE(sizeof(short), 2);
    EXPECT_GE(sizeof(int), 2);
    EXPECT_GE(sizeof(long), 4);     // CPU data register size
    EXPECT_GE(sizeof(long long), 8);
    EXPECT_FALSE(typeid(signed char) == typeid(char));
    EXPECT_EQ(typeid(short), typeid(short int));
    EXPECT_EQ(typeid(short), typeid(signed short));
    EXPECT_EQ(typeid(long), typeid(long int));
    EXPECT_EQ(typeid(long), typeid(signed long));
    EXPECT_EQ(typeid(long long), typeid(long long int));
    EXPECT_EQ(typeid(long long), typeid(signed long long));
}

TEST(CppBasicTypes, unsigned_integers) {
    PRINT_TYPE_SIZE(unsigned char);
    PRINT_TYPE_SIZE(unsigned short);
    PRINT_TYPE_SIZE(unsigned);
    PRINT_TYPE_SIZE(unsigned long);
    PRINT_TYPE_SIZE(unsigned long long);
    // Assert
    EXPECT_NE(typeid(unsigned char), typeid(signed char));
    EXPECT_NE(typeid(unsigned short), typeid(short));
    EXPECT_NE(typeid(unsigned), typeid(int));
    EXPECT_EQ(typeid(unsigned), typeid(unsigned int));
    EXPECT_NE(typeid(unsigned long), typeid(long));
    EXPECT_NE(typeid(unsigned long long), typeid(long long));
}

TEST(CppBasicTypes, floating_points) {
    PRINT_TYPE_SIZE(float);
    PRINT_TYPE_SIZE(double);
    PRINT_TYPE_SIZE(long double);
    // Assert
    EXPECT_GE(sizeof(float), sizeof(int));
    EXPECT_GE(sizeof(double), sizeof(float));   // CPU data register size
    EXPECT_GE(sizeof(long double), sizeof(double));
}

TEST(CppBasicTypes, pointers) {
    PRINT_TYPE_SIZE(void*);
    PRINT_TYPE_SIZE(char*);
    PRINT_TYPE_SIZE(long*);
    PRINT_TYPE_SIZE(double*);
    // Assert
    EXPECT_EQ(sizeof(void*), sizeof(double*));  // CPU address register size
    EXPECT_EQ(sizeof(void*), sizeof(char*));
    EXPECT_EQ(sizeof(void*), sizeof(long*));
    EXPECT_NE(typeid(void*), typeid(double*));
    EXPECT_NE(typeid(void*), typeid(char*));
    EXPECT_NE(typeid(void*), typeid(long*));
}

TEST(CppBasicTypes, arrays) {
    PRINT_TYPE_NAME(char[]);
    PRINT_TYPE_SIZE(long[0]);
    PRINT_TYPE_NAME(double[][0]);
    PRINT_TYPE_SIZE(double[0][0]);
    // Arrange
    constexpr size_t size = 10;
    // Act
    long array_1d[size];
    long array_2d[size][size];
    // Assert
    EXPECT_EQ(sizeof(array_1d), sizeof(array_1d[0])*size);
    EXPECT_EQ(sizeof(array_2d), sizeof(array_2d[0][0])*size*size);
    EXPECT_EQ(typeid(array_2d[0]), typeid(array_1d));
    EXPECT_EQ(sizeof(array_2d), sizeof(array_2d[0])*size);
}

TEST(CppBasicTypes, other_types) {
    PRINT_TYPE_SIZE(bool);
    PRINT_TYPE_NAME(void);  // compiler warnings sizeof(void) and return 1.
    PRINT_TYPE_SIZE(decltype(nullptr));
    PRINT_TYPE_SIZE(size_t);
    PRINT_TYPE_SIZE(time_t);
    // Assert
    EXPECT_EQ(sizeof(bool), 1);
    EXPECT_EQ(sizeof(nullptr), sizeof(void*));
    EXPECT_GE(sizeof(size_t), 4);
    EXPECT_EQ(typeid(nullptr), typeid(std::nullptr_t));
    EXPECT_NE(typeid(nullptr), typeid(void*));
    EXPECT_EQ(typeid(size_t), typeid(unsigned long));
}
