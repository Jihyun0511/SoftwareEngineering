#pragma once
#pragma once
#include <vector>
#include <memory>
#include "Bicycle.h"

//������ ���� Ŭ����
class BicycleRepository {
private:
    std::vector<std::shared_ptr<Bicycle>> bicycles;

public:
    void addBicycle(const std::shared_ptr<Bicycle>& b);
    //������ ��ȸ
    std::shared_ptr<Bicycle> findBicycleByID(const std::string& id) const;
};
