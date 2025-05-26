#include "Bicycle.h"

Bicycle::Bicycle(const std::string& id, const std::string& model)
    : bicycleID(id), modelName(model) {
}

//자전거 ID 조회
const std::string& Bicycle::getBicycleID() const {
    return bicycleID;
}

//자전거 모델명 조회
const std::string& Bicycle::getModelName() const {
    return modelName;
}
