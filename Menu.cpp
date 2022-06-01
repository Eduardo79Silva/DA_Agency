//
// Created by zediogo96 on 30/05/22.
//

#include "Menu.h"

#include "limits"

using namespace std;

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <iostream>

#endif


Menu::Menu() = default;;

Menu::~Menu() = default;

Menu* Menu::getNextMenu() { return this->next_menu; }

void Menu::setNextMenu(Menu* new_menu) {
    this->next_menu = new_menu;
}

MainMenu::MainMenu() : Menu() { }

void MainMenu::display() {

    int option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             MAIN MENU             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|   Choose your desired dataset:    |" << endl;
    cout << "|                                   |" << endl;

    for(int i = 0; i < 11; i++) {
        std::cout  << "|    [" << i << "] " << setw(6 - (to_string(i).length() + 2)) << left  << "Dataset" << " "
        << setw(20 - to_string(i).length()) << left << i  << "|" << std::endl;
    }
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    if (option >= 0 && option <= 11) {
        application->readData(to_string(option));
        application->getNetwork()->print();
        setNextMenu(new IntermediateMenu());
    }
}

IntermediateMenu::IntermediateMenu() : Menu() {};

void IntermediateMenu::display() {

    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             MAIN MENU             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|   Select your scenery:            |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Scenery 1                   |" << endl;
    cout << "|   [2] Scenery 2                   |" << endl;
    cout << "|   [3] Teste 2.5                   |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1':

            cout << Network::getInstance()->getNetwork()->correctGroupSize(1,2, 2) << endl;
            break;
        case '2':
            cout << "min dur: "  << Network::getInstance()->getNetwork()->earliestStart() <<endl;
            Network::getInstance()->getNetwork()->latestFinish();

            for (int i = 1; i <= Network::getInstance()->getNetwork()->getNodes().size(); i++) {
                if (Network::getInstance()->getNetwork()->getNodes()[i].dist != std::numeric_limits<int>::min())
                    cout << "ES: " << Network::getInstance()->getNetwork()->getNodes()[i].ES << " LF: " << Network::getInstance()->getNetwork()->getNodes()[i].LF << endl;
            }
            break;
        case '3':
            Network::getInstance()->getNetwork()->node_wait_times(1,7);
            break;
        case '0':
            setNextMenu(nullptr);
            break;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}

Scenery1_Menu::Scenery1_Menu() : Menu() {}

void Scenery1_Menu::display() {

    int option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             Scenery 1             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Exec                        |" << endl;
    cout << "|   [2] Print                       |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch (option) {
        case 1: {

            break;
        }
        case 2:
            /*Application::getInstance()->printDeliveryMan(false);*/
            sleep(4);
            break;
        case 0: return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }
}

Scenery2_Menu::Scenery2_Menu() : Menu() {}

void Scenery2_Menu::display() {
    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             Scenery 2             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Exec                        |" << endl;
    cout << "|   [2] Print                       |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Exit                        |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1': {
            /*this->application->scenery2();*/
            sleep(4);
            break;
        }
        case '2':
            /*Application::getInstance()->printDeliveryMan(true);*/
            sleep(4);
            break;
        case '0': return;
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }

}