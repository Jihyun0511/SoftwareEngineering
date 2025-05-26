#include "CommandBoundary.h"
#include <fstream>
#include <memory>
#include "MemberRepository.h"
#include "BicycleRepository.h"
#include "RegistrationController.h"
#include "AuthenticationController.h"
#include "BicycleController.h"

void CommandBoundary::processCommands(const std::string& inputFilePath,
    const std::string& outputFilePath)
{
    std::ifstream in(inputFilePath);
    std::ofstream out(outputFilePath);

    MemberRepository memberRepo;
    BicycleRepository bicycleRepo;

    RegistrationController regCtrl(memberRepo);
    AuthenticationController authCtrl(memberRepo);
    BicycleController bikeCtrl(memberRepo, bicycleRepo);

    std::shared_ptr<User> currentUser = nullptr;

    int menu1, menu2;
    bool isExit = false;

    while (!isExit && (in >> menu1 >> menu2)) {
        switch (menu1) {
        case 1:
            if (menu2 == 1) {
                std::string id, pwd, phone;
                in >> id >> pwd >> phone;
                regCtrl.signUp(id, pwd, phone);
                out << "1.1.회원가입" << std::endl;
                out << "> " << id << " " << pwd << " " << phone << std::endl << std::endl;
            }
            break;

        case 2:
            if (menu2 == 1) {
                std::string id, pwd;
                in >> id >> pwd;
                currentUser = authCtrl.login(id, pwd);
                out << "2.1.로그인" << std::endl;
                out << "> " << id << " " << pwd << std::endl << std::endl;
            }
            else if (menu2 == 2) {
                authCtrl.logout();
                out << "2.2.로그아웃" << std::endl;
                if (currentUser) {
                    out << "> " << currentUser->getUserID() << std::endl;
                }
                out << std::endl;
                currentUser.reset();
            }
            break;

        case 3:
            if (menu2 == 1) {
                std::string bid, model;
                in >> bid >> model;
                bikeCtrl.registerBicycle(currentUser, bid, model);
                out << "3.1.자전거 등록" << std::endl;
                out << "> " << bid << " " << model << std::endl << std::endl;
            }
            break;

        case 4:
            if (menu2 == 1) {
                std::string bid;
                in >> bid;
                auto memberPtr = std::dynamic_pointer_cast<Member>(currentUser);
                bikeCtrl.rentBicycle(memberPtr, bid);
                auto bike = bicycleRepo.findBicycleByID(bid);
                if (bike) {
                    out << "4.1.자전거 대여" << std::endl;
                    out << "> " << bike->getBicycleID() << " " << bike->getModelName() << std::endl << std::endl;
                }
            }
            break;

        case 5:
            if (menu2 == 1) {
                out << "5.1.자전거 대여 리스트" << std::endl;
                auto memberPtr = std::dynamic_pointer_cast<Member>(currentUser);
                for (auto& b : bikeCtrl.showRentedBicycles(memberPtr)) {
                    out << "> " << b->getBicycleID() << " " << b->getModelName() << std::endl;
                }
                out << std::endl;
            }
            break;

        case 6:
            if (menu2 == 1) {
                out << "6.1.종료" << std::endl;
                isExit = true;
            }
            break;

        default:
            break;
        }
    }

    in.close();
    out.close();
}

