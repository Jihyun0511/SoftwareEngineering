#include "User.h"
#include "Bicycle.h"
#include <vector>
#include <memory>

User::User(const std::string& id, const std::string& pwd)
    : userID(id), password(pwd) {
}

const std::string& User::getUserID() const {
    return userID;
}

const std::string& User::getPassword() const {
    return password;
}

Member::Member(const std::string& id, const std::string& pwd, const std::string& phone)
    : User(id, pwd), phoneNumber(phone) {
}

//대여 자전거 추가
void Member::addRentedBicycle(const std::shared_ptr<Bicycle>& bike) {
    rentedBicycles.push_back(bike);
}

//대여한 자전거 목록 조회
const std::vector<std::shared_ptr<Bicycle>>& Member::getRentedBicycles() const {
    return rentedBicycles;
}

Admin::Admin(const std::string& id, const std::string& pwd)
    : User(id, pwd) {
}
