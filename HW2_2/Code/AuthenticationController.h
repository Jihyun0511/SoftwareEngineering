#pragma once
#include <memory>
#include "MemberRepository.h"
#include "User.h"

class AuthenticationController {
private:
    MemberRepository& memberRepo;

public:
    AuthenticationController(MemberRepository& repo);
    std::shared_ptr<User> login(const std::string& userID, const std::string& password);
    void logout();
};

