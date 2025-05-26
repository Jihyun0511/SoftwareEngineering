#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Bicycle.h"

//����(ȸ��, ������) Ŭ����
class User {
protected:
    std::string userID; //����� ID
    std::string password; //��й�ȣ

public:
    User(const std::string& id, const std::string& pwd);
    virtual ~User() = default;
    const std::string& getUserID() const;
    const std::string& getPassword() const;
};

//ȸ�� Ŭ����
class Member : public User {
private:
    std::string phoneNumber; //��ȭ��ȣ
    std::vector<std::shared_ptr<Bicycle>> rentedBicycles; //�뿩�� ������ ���

public:
    Member(const std::string& id, const std::string& pwd, const std::string& phone);
    void addRentedBicycle(const std::shared_ptr<Bicycle>& bike); //������ �뿩 ��� �߰�
    const std::vector<std::shared_ptr<Bicycle>>& getRentedBicycles() const; //������ �뿩 ��� ��ȸ
};

class Admin : public User {
public:
    Admin(const std::string& id, const std::string& pwd);
};
