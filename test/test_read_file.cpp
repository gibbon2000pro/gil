#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

void ReadFile(const std::string& name) {
    std::ifstream file(name, std::ios::in | std::ios::binary);
    if (!file) {
        return;
    }

    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::setlocale(LC_ALL, "zh_CN.UTF-8");
    // file.imbue(std::locale("zh_CN.UTF-8"));

    std::wcout << L"贺渊凌" << std::endl;

    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        // std::cout << line << std::endl;
        // for (auto& c : line) {
        //     std::cout << c << std::endl;
        // }
        std::wstring wline = conv.from_bytes(line);
        std::wcout << wline.length() << std::endl;
        std::wcout << wline << std::endl;
        // wprintf(L"%ls\n", wline);
        for (auto& c : wline) {
            std::wcout << c << std::endl;
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc > 0) {
        std::string arg0(argv[0]);
        // std::cout << "arg0:" << arg0 << std::endl;
    }

    if (argc > 1) {
        std::string arg1(argv[1]);
        // std::cout << "arg1:" << arg1 << std::endl;

        ReadFile(arg1);
    }

    return 0;
}