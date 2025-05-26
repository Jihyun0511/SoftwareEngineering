#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Bicycle.h"

class User {
protected:
    std::string userID;
    std::string password;

public:
    User(const std::string& id, const std::string& pwd);
    virtual ~User() = default;
    const std::string& getUserID() const;
    const std::string& getPassword() const;
};

class Member : public User {
private:
    std::string phoneNumber;
    std::vector<std::shared_ptr<Bicycle>> rentedBicycles;

public:
    Member(const std::string& id, const std::string& pwd, const std::string& phone);
    void addRentedBicycle(const std::shared_ptr<Bicycle>& bike);
    const std::vector<std::shared_ptr<Bicycle>>& getRentedBicycles() const;
};

class Admin : public User {
public:
    Admin(const std::string& id, const std::string& pwd);
};
