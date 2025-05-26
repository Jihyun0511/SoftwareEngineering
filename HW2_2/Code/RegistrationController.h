#pragma once
#include <memory>
#include "MemberRepository.h"

//회원가입 로직 컨트롤러
class RegistrationController {
private:
    MemberRepository& memberRepo;

public:
    RegistrationController(MemberRepository& repo);
    //회원가입
    std::shared_ptr<Member> signUp(const std::string& userID,
        const std::string& password,
        const std::string& phoneNumber);
};
