#include "MemberRepository.h"

void MemberRepository::addMember(const std::shared_ptr<Member>& m) {
    members.push_back(m);
}

//ȸ�� ��ȸ
std::shared_ptr<Member> MemberRepository::findMemberByID(const std::string& id) const {
    for (auto& m : members) {
        if (m->getUserID() == id) {
            return m;
        }
    }
    return nullptr;
}
