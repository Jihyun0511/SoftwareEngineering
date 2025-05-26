#pragma once
#include <string>

//파일 입출력 바운더리 클래스
class CommandBoundary {
public:
    void processCommands(const std::string& inputFilePath,
        const std::string& outputFilePath);
};
