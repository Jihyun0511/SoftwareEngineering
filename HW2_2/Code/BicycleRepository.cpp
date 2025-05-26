#include "BicycleRepository.h"

void BicycleRepository::addBicycle(const std::shared_ptr<Bicycle>& b) {
    bicycles.push_back(b);
}

//자전거 조회
std::shared_ptr<Bicycle> BicycleRepository::findBicycleByID(const std::string& id) const {
    for (auto& b : bicycles) {
        if (b->getBicycleID() == id) {
            return b;
        }
    }
    return nullptr;
}

