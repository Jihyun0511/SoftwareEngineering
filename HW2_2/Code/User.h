#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Bicycle.h"

//유저(회원, 관리자) 클래스
class User {
protected:
    std::string userID; //사용자 ID
    std::string password; //비밀번호

public:
    User(const std::string& id, const std::string& pwd);
    virtual ~User() = default;
    const std::string& getUserID() const;
    const std::string& getPassword() const;
};

//회원 클래스
class Member : public User {
private:
    std::string phoneNumber; //전화번호
    std::vector<std::shared_ptr<Bicycle>> rentedBicycles; //대여한 자전거 목록

public:
    Member(const std::string& id, const std::string& pwd, const std::string& phone);
    void addRentedBicycle(const std::shared_ptr<Bicycle>& bike); //자전거 대여 목록 추가
    const std::vector<std::shared_ptr<Bicycle>>& getRentedBicycles() const; //자전거 대여 목록 조회
};

class Admin : public User {
public:
    Admin(const std::string& id, const std::string& pwd);
};
