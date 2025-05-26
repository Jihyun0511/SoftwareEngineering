#include "Bicycle.h"

Bicycle::Bicycle(const std::string& id, const std::string& model)
    : bicycleID(id), modelName(model) {
}

const std::string& Bicycle::getBicycleID() const {
    return bicycleID;
}

const std::string& Bicycle::getModelName() const {
    return modelName;
}
