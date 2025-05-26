#pragma once
#include <string>

//자전거 정보 엔티티 클래스
class Bicycle {
private:
    std::string bicycleID; //자전거 ID
    std::string modelName; //자전거 모델명

public:
    Bicycle(const std::string& id, const std::string& model);
    const std::string& getBicycleID() const; //자전거 ID 조회
    const std::string& getModelName() const; //자전거 모델명 조회
};
