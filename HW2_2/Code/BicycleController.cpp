#include "BicycleController.h"
#include "User.h" 

BicycleController::BicycleController(MemberRepository& mRepo,
    BicycleRepository& bRepo)
    : memberRepo(mRepo), bicycleRepo(bRepo) {
}

//자전거 등록
void BicycleController::registerBicycle(const std::shared_ptr<User>& admin,
    const std::string& bicycleID,
    const std::string& modelName)
{
    //관리자 검증
    if (std::dynamic_pointer_cast<Admin>(admin)) {
        auto bike = std::make_shared<Bicycle>(bicycleID, modelName);
        bicycleRepo.addBicycle(bike);
    }
}

//자전거 대여
void BicycleController::rentBicycle(const std::shared_ptr<Member>& member,
    const std::string& bicycleID)
{
    auto bike = bicycleRepo.findBicycleByID(bicycleID);
    if (member && bike) {
        member->addRentedBicycle(bike);
    }
}

//대여한 자전거 조회
std::vector<std::shared_ptr<Bicycle>> BicycleController::showRentedBicycles(const std::shared_ptr<Member>& member) const
{
    if (member) {
        return member->getRentedBicycles();
    }
    return {};
}
