// 1. program structure and system interaction
// 2. iostream std::cout

#include <iostream>
#include <vector>


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


// print environment variables. last element of env[] is nullptr.
void print_env(char** env)
{
    if (*env != nullptr) {
        std::cout << "\n[ENVIRONMENT VARIABLES]" << std::endl;
    }
    while (*env != nullptr) {
        std::cout << *env << std::endl;
        ++env;
    }
}


using words_t = std::vector<std::string>;
// call by reference will be faster than call by value for compound types
void print_msg(words_t const& msg)
{
    for (auto& word : msg) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[], char** env)
{
    const words_t msg{"Hello", "C++", "World", "from", "VS Code!"};
    print_msg(msg);
    print_msg({"and", "the C++ extension!"});

    if (argc > 1) {
        print_args(argc, argv);
        // compared by std::string::operator==(lhs,rhs) overriding.
        if (std::string(argv[1]) == "env") {
            print_env(env);
        }
        if (std::string(argv[1]) == "exit") {
            // program exit with failure code. (non-zero value, effective value:1-255)
            std::exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;   // same as exit(0);
}