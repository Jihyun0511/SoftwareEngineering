#pragma once
#include <memory>
#include "MemberRepository.h"

//ȸ������ ���� ��Ʈ�ѷ�
class RegistrationController {
private:
    MemberRepository& memberRepo;

public:
    RegistrationController(MemberRepository& repo);
    //ȸ������
    std::shared_ptr<Member> signUp(const std::string& userID,
        const std::string& password,
        const std::string& phoneNumber);
};
