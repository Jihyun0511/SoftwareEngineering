#pragma once
#include <vector>
#include <memory>
#include "User.h"

//회원 관리 클래스
class MemberRepository {
private:
    std::vector<std::shared_ptr<Member>> members;

public:
    void addMember(const std::shared_ptr<Member>& m);
    std::shared_ptr<Member> findMemberByID(const std::string& id) const; //회원 조회
};
