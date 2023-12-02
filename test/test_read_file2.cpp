#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

struct CodeFile;

struct CodeLine {
    CodeFile* mCode;
    std::wstring mContent;
    int mLineNumber;
};

struct CodeFile {
    const std::string mFileName;
    std::vector<CodeLine> mLines;
    bool mValid;

    CodeFile(const std::string& name)
        : mFileName(name),
          mValid(false) {
        std::ifstream file(name, std::ios::in | std::ios::binary);
        if (!file) {
            return;
        }
        std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
        int lineNum = 0;
        while (!file.eof()) {
            std::string line;
            std::getline(file, line);
            mLines.emplace_back();
            auto& codeLine = mLines.back();
            codeLine.mCode = this;
            codeLine.mLineNumber = ++lineNum;
            codeLine.mContent = conv.from_bytes(line);
        }
        mValid = true;
        file.close();
    }
};

void ReadFile(const std::string& name) {
    CodeFile code(name);
    if (!code.mValid) {
        return;
    }
    for (auto& line : code.mLines) {
        std::wcout << L"LineNumber:" << line.mLineNumber
                   << L" -> " << line.mContent << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::setlocale(LC_ALL, "zh_CN.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

    std::wcout << L"贺渊凌1" << std::endl;

    if (argc > 0) {
        std::string arg0(argv[0]);
        std::wcout << L"arg0:" << conv.from_bytes(arg0) << std::endl;
    }

    std::wcout << L"贺渊凌2" << std::endl;

    if (argc > 1) {
        std::string arg1(argv[1]);
        std::wcout << L"arg1:" << conv.from_bytes(arg1) << std::endl;

        std::wcout << L"贺渊凌3" << std::endl;

        ReadFile(arg1);

        std::wcout << L"贺渊凌4" << std::endl;
    }

    return 0;
}