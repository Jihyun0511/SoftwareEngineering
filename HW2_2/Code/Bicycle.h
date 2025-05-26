#pragma once
#include <string>

class Bicycle {
private:
    std::string bicycleID;
    std::string modelName;

public:
    Bicycle(const std::string& id, const std::string& model);
    const std::string& getBicycleID() const;
    const std::string& getModelName() const;
};
