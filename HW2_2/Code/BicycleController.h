#pragma once
#include <memory>
#include "MemberRepository.h"
#include "BicycleRepository.h"
#include "User.h"

class BicycleController {
private:
    MemberRepository& memberRepo;
    BicycleRepository& bicycleRepo;

public:
    BicycleController(MemberRepository& mRepo, BicycleRepository& bRepo);
    void registerBicycle(const std::shared_ptr<User>& admin,
        const std::string& bicycleID,
        const std::string& modelName);
    void rentBicycle(const std::shared_ptr<Member>& member,
        const std::string& bicycleID);
    std::vector<std::shared_ptr<Bicycle>> showRentedBicycles(const std::shared_ptr<Member>& member) const;
};
