#pragma once
#include <memory>
#include "MemberRepository.h"
#include "User.h"

//회원용 로그인아웃 컨트롤러
class AuthenticationController {
private:
    MemberRepository& memberRepo;

public:
    AuthenticationController(MemberRepository& repo);
    std::shared_ptr<User> login(const std::string& userID, const std::string& password); //로그인
    void logout(); //로그아웃
};

