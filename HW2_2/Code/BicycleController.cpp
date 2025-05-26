#include "BicycleController.h"
#include "User.h" // for dynamic cast

BicycleController::BicycleController(MemberRepository& mRepo,
    BicycleRepository& bRepo)
    : memberRepo(mRepo), bicycleRepo(bRepo) {
}

void BicycleController::registerBicycle(const std::shared_ptr<User>& admin,
    const std::string& bicycleID,
    const std::string& modelName)
{
    if (std::dynamic_pointer_cast<Admin>(admin)) {
        auto bike = std::make_shared<Bicycle>(bicycleID, modelName);
        bicycleRepo.addBicycle(bike);
    }
}

void BicycleController::rentBicycle(const std::shared_ptr<Member>& member,
    const std::string& bicycleID)
{
    auto bike = bicycleRepo.findBicycleByID(bicycleID);
    if (member && bike) {
        member->addRentedBicycle(bike);
    }
}

std::vector<std::shared_ptr<Bicycle>> BicycleController::showRentedBicycles(const std::shared_ptr<Member>& member) const
{
    if (member) {
        return member->getRentedBicycles();
    }
    return {};
}
