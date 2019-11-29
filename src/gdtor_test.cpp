#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

template<typename T>
class TestClass {
    T val;
public:
    TestClass() { std::cout << "TestClass<" << typeid(T).name() << ">()" << std::endl; }
    TestClass(T x) { std::cout << "TestClass<" << typeid(T).name() << ">(" << x << ")" << std::endl; }
    ~TestClass() { std::cout << "~TestClass<" << typeid(T).name() << ">()" << std::endl; }
};

using test_int_t = std::shared_ptr<TestClass<int>>;
typedef std::vector<test_int_t> test_container_t;

// global constructor for container only (no elements)
test_container_t intClassC;
std::unordered_map<int,TestClass<double>> doubleClassC;
// global constructor for TestClass
TestClass<char> charClass;

int main(int argc, const char* argv[]) {
    std::cout << "BEGIN" << std::endl;
    // add a new element at the end of the vector
    intClassC.push_back(std::make_shared<TestClass<int>>());
    intClassC.push_back(std::make_shared<TestClass<int>>(10));
    // insert a new element to unordered_map
    doubleClassC[10];
    std::cout << "END" << std::endl;
} // global destructor will be performed