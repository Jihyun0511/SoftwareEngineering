#pragma once
#include <memory>
#include "MemberRepository.h"
#include "BicycleRepository.h"
#include "User.h"

//자전거 등록 대여 조회
class BicycleController {
private:
    MemberRepository& memberRepo;
    BicycleRepository& bicycleRepo;

public:
    BicycleController(MemberRepository& mRepo, BicycleRepository& bRepo);
    //자전거 등록
    void registerBicycle(const std::shared_ptr<User>& admin,
        const std::string& bicycleID,
        const std::string& modelName);
    //자전거 대여
    void rentBicycle(const std::shared_ptr<Member>& member,
        const std::string& bicycleID);
    //대여한 자전거 조회
    std::vector<std::shared_ptr<Bicycle>> showRentedBicycles(const std::shared_ptr<Member>& member) const;
};
