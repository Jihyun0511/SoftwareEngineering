#pragma once
#include <string>

//���� ����� �ٿ���� Ŭ����
class CommandBoundary {
public:
    void processCommands(const std::string& inputFilePath,
        const std::string& outputFilePath);
};
