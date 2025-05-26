#pragma once
#pragma once
#include <vector>
#include <memory>
#include "Bicycle.h"

//자전거 관리 클래스
class BicycleRepository {
private:
    std::vector<std::shared_ptr<Bicycle>> bicycles;

public:
    void addBicycle(const std::shared_ptr<Bicycle>& b);
    //자전거 조회
    std::shared_ptr<Bicycle> findBicycleByID(const std::string& id) const;
};
