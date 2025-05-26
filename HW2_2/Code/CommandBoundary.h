#pragma once
#include <string>

class CommandBoundary {
public:
    void processCommands(const std::string& inputFilePath,
        const std::string& outputFilePath);
};
