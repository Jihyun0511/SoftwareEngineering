#pragma once
#include <string>

//������ ���� ��ƼƼ Ŭ����
class Bicycle {
private:
    std::string bicycleID; //������ ID
    std::string modelName; //������ �𵨸�

public:
    Bicycle(const std::string& id, const std::string& model);
    const std::string& getBicycleID() const; //������ ID ��ȸ
    const std::string& getModelName() const; //������ �𵨸� ��ȸ
};
