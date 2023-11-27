#include <fstream>
#include <iostream>
#include <string>

void ReadFile(const std::string& name) {
    std::ifstream file(name, std::ios::in | std::ios::binary);
    if (!file) {
        return;
    }
}

int main(int argc, char* argv[]) {
    if (argc > 0) {
        std::string arg0(argv[0]);
        std::cout << "arg0:" << arg0 << std::endl;
    }

    if (argc > 1) {
        std::string arg1(argv[1]);
        std::cout << "arg1:" << arg1 << std::endl;
    }

    return 0;
}