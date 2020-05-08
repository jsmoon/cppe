# C/C++ Programming Practical Examples
This project is for collecting useful example codes.
As I learn more C/C++ programming skills, I could add more examples.


## Helper Scripts
- `./b` - build and run C++ source file.
### TODO
- `./a` - build and run all C++ source files in the src/ and test/.
- `./t` - run all test binaries.


## Examples - `src/`
- `helloworld.cpp` - basic program structure and system interaction with std::iostream
- `inspect_gdtor.cpp` - show global destructor called.


## Setup VSCode Environment
This examples fit on `WSL:Ubuntu` environment.
`.vscode/` includes settings for it.

### To remove clangd error in WSL:Ubuntu
```bash
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-8 100
```

### To install libgtest-dev for googletest
```bash
sudo apt-get install libgtest-dev
sudo apt-get install cmake # install cmake

cd /usr/src/googletest
sudo cmake CMakeLists.txt
sudo make

sudo cp *.a /usr/lib
sudo mkdir -p /usr/local/lib/gtest
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a
```
