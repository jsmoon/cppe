// 1. program structure and system interaction
// 2. iostream std::cout

#include <iostream>
#include <vector>
#include <unistd.h>     // environ
#include <cassert>


// print arguments from command line. argv[0] has this program name.
void print_args(int const argc, char* argv[])
{
    if (argc > 0) {
        std::cout << "\n[COMMAND LINE ARGUMENTS]" << std::endl;
    }
    for (int i=0; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
}


// print environment variables. last element of envp[] is nullptr.
void print_env(char** envp)
{
    if (*envp != nullptr) {
        std::cout << "\n[ENVIRONMENT VARIABLES]" << std::endl;
    }
    while (*envp != nullptr) {
        std::cout << *envp << std::endl;
        ++envp;
    }
}


using words_t = std::vector<std::string>;
// call by reference will be faster than call by value for compound types
void print_msg(words_t const& words)
{
    for (auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}


// NOTE: char** envp is not a standard way.
int main(int argc, char* argv[], char** envp)
{
    const words_t words{"Hello", "C++", "World", "from", "VS Code!"};
    print_msg(words);
    print_msg({"and", "the C++ extension!"});

    if (argc > 1) {
        print_args(argc, argv);
        // compared by std::string::operator==(lhs,rhs) overriding.
        if (std::string(argv[1]) == "env") {
            print_env(envp);
            // const char* environ[] defined at unistd.h. (mentioned at POSIX.1)
            if (envp != environ) {
                assert(envp == environ);
            }
        }
        if (std::string(argv[1]) == "exit") {
            // program exit with failure code. (non-zero value, effective value:1-255)
            std::exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;   // same as exit(0);
}