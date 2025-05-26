#include "RegistrationController.h"
#include "User.h"

RegistrationController::RegistrationController(MemberRepository& repo)
    : memberRepo(repo) {
}

//회원가입
std::shared_ptr<Member> RegistrationController::signUp(const std::string& userID,
    const std::string& password,
    const std::string& phoneNumber)
{
    auto member = std::make_shared<Member>(userID, password, phoneNumber);
    memberRepo.addMember(member);
    return member;
}

