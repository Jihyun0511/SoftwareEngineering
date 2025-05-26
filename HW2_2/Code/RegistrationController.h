#pragma once
#include <memory>
#include "MemberRepository.h"

class RegistrationController {
private:
    MemberRepository& memberRepo;

public:
    RegistrationController(MemberRepository& repo);
    std::shared_ptr<Member> signUp(const std::string& userID,
        const std::string& password,
        const std::string& phoneNumber);
};
