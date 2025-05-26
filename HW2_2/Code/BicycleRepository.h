#pragma once
#pragma once
#include <vector>
#include <memory>
#include "Bicycle.h"

class BicycleRepository {
private:
    std::vector<std::shared_ptr<Bicycle>> bicycles;

public:
    void addBicycle(const std::shared_ptr<Bicycle>& b);
    std::shared_ptr<Bicycle> findBicycleByID(const std::string& id) const;
};
