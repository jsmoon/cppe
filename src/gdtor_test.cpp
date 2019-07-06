#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

template<typename T>
class TestClass {
    T x;
public:
    TestClass() { std::cout << "TestClass()" << typeid(T).name() << std::endl; }
    ~TestClass() { std::cout << "~TestClass()" << typeid(T).name() << std::endl; }
};

using test_int_t = std::shared_ptr<TestClass<int>>;
typedef std::vector<test_int_t> test_container_t;
test_container_t intClassC;
std::unordered_map<int,TestClass<double>> doubleClassC;
TestClass<char> charClass;

int main(int argc, const char* argv[]) {
    std::cout << "BEGIN" << std::endl;
    intClassC.push_back(static_cast<std::shared_ptr<TestClass<int>>>(new TestClass<int>()));
    doubleClassC[10];
    std::cout << "END" << std::endl;
}