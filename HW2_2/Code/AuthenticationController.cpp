#include "AuthenticationController.h"
#include "User.h"

AuthenticationController::AuthenticationController(MemberRepository& repo)
    : memberRepo(repo) {
}

std::shared_ptr<User> AuthenticationController::login(const std::string& userID,
    const std::string& password)
{
    //관리자 계정 고정
    if (userID == "admin" && password == "admin") {
        return std::make_shared<Admin>(userID, password);
    }
    //회원인 경우
    auto member = memberRepo.findMemberByID(userID);
    if (member && member->getPassword() == password) {
        return member;
    }
    return nullptr;
}

void AuthenticationController::logout() {}