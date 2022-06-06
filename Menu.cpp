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



void display_scen1_description() {
    cout << "[1.1] Maximizes the dimension of the group and indicates any of the available paths." << endl;
    cout << "[1.2] Maximizes the dimension of the group, and minimizes the number of transport\n"
            "changes, without giving priority to one of the criteria, displaying both optimal solutions \n"
            "That means that a bigger group can be transported if it admits more transport changes, \n"
            "or if you want less transport changes, the dimension of the group can be smaller. " << endl;
}

void display_scen2_description() {
    cout << "[2.1] Determines a path for a group, given it's size. " << endl;
    cout << "[2.2] Corrects an path, if necessary, so the dimension of a given group (from 2.1) \n"
            "can expand a given number of units" << endl;
    cout << "[2.3] Determines the maximum dimension of a group and a path. " << endl;
    cout << "[2.4] Starting from a path that is a acyclic graph, determine the minimum time \n"
            "that it would take the group reunite again at the destination." << endl;
    cout << "[2.5] Given the 2.4 conditions, admiting that the elements of the group depart \n"
            "from the same place at the same time (earliest time possible), indicate the maximum \n"
            "wait time and in which places there were elements waiting." << endl;
}
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

    for(int i = 1; i < 11; i++) {
        std::cout  << "|    [" << i << "] " << setw(6 - (to_string(i).length() + 2)) << left  << "Dataset" << " "
        << setw(20 - to_string(i).length()) << left << i  << "|" << std::endl;
    }
    cout << "|                                   |" << endl;
    cout << "|    [0] Exit                       |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;


    if (option >= 1 && option <= 10) {
        application->readData(to_string(option));
        //application->getNetwork()->print();
        setNextMenu(new IntermediateMenu());
    }
    else if (option == 0) exit(0);
    else std::cout << "Invalid Input \n:";
}

IntermediateMenu::IntermediateMenu() : Menu() {};

void IntermediateMenu::display() {

    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|      SCENERY CHOOSING MENU        |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|   Select your scenery:            |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [1] Scenery 1: Groups that      |" << endl;
    cout << "|   will not separate               |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [2] Scenery 2: Groups that      |" << endl;
    cout << "|   can separate from each other    |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Return                      |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    switch ((char) option) {
        case '1':
            setNextMenu(new Scenery1_Menu());
            break;
        case '2':
            setNextMenu(new Scenery2_Menu());
            break;
        case '0': {
            Network::getInstance()->setShouldPop(true);
            break;
        }
        default: std::cout << "Invalid Input \n:";
    }
}

Scenery1_Menu::Scenery1_Menu() : Menu() {}

void Scenery1_Menu::display() {

    char option;

    using namespace std;

    cout << std::endl;
    cout << "_____________________________________" << endl;
    cout << "|             Scenery 1             |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [.1]                            |" << endl;
    cout << "|   [.2]                            |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [h] Description of problems     |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Return                      |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    int start, end;

    switch ((char) option) {
        case '1': {

            int start = Network::getInstance()->askNodesInput("Please input the Start Node ");
            int end = Network::getInstance()->askNodesInput("Please input the End Node ");

            Network::getInstance()->getNetwork()->dijkstra(start);
            cout << "Max capacity path: ";
            Network::getInstance()->getNetwork()->maximumFlowPath(1);
            Network::getInstance()->getNetwork()->get_path(start, end, true);
            cout << "Capacity: ";
            cout << Network::getInstance()->getNetwork()->path_Capacity(Network::getInstance()->getNetwork()->get_path(start, end, false));

            sleep(4);
            break;

        }
        case '2':

            start = Network::getInstance()->askNodesInput("Please input the Start Node ");
            end = Network::getInstance()->askNodesInput("Please input the End Node ");

            cout << "Shortest path: ";
            Network::getInstance()->getNetwork()->dijkstra(1);
            Network::getInstance()->getNetwork()->get_path(start, end, true);
            cout << "Capacity: ";
            cout << Network::getInstance()->getNetwork()->path_Capacity(Network::getInstance()->getNetwork()->get_path(start, end, false));
            cout << "Max capacity path: ";
            Network::getInstance()->getNetwork()->maximumFlowPath(1);
            Network::getInstance()->getNetwork()->get_path(start, end, true);
            cout << "Capacity: ";
            cout << Network::getInstance()->getNetwork()->path_Capacity(Network::getInstance()->getNetwork()->get_path(start, end, false));
            sleep(4);
            break;
        case 'h':
            display_scen1_description();
            sleep(4);
            break;
        case '0': {
            Network::getInstance()->setShouldPop(true);
            break;
        }
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
    cout << "|   [.1]                            |" << endl;
    cout << "|   [.2]                            |" << endl;
    cout << "|   [.3]                            |" << endl;
    cout << "|   [.4]                            |" << endl;
    cout << "|   [.5]                            |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [h] Description of problems     |" << endl;
    cout << "|                                   |" << endl;
    cout << "|   [0] Return                      |" << endl;
    cout << "|___________________________________|" << endl;

    std::cout << "Please input your choice: " << std::endl << std::flush;
    std::cin >> option;

    int start, end, size;

    switch ((char) option) {
        case '1': {
            start = Network::getInstance()->askNodesInput("Please input the Start Node ");
            end = Network::getInstance()->askNodesInput("Please input the End Node ");
            size = Network::getInstance()->askNodesInput("Please input the size of the group ");
            cout << Network::getInstance()->getNetwork()->correctGroupSize(start,end, size, false) << endl;
            cout << Network::getInstance()->getNetwork()->correctGroupSize(start,end, 2, true) << endl;

            break;
        }
        case '2':
            size = Network::getInstance()->askNodesInput("Please input the size of the increment of the group ");
            cout << Network::getInstance()->getNetwork()->correctGroupSize(start,end, size, true) << endl;
            break;
        case '3':
            start = Network::getInstance()->askNodesInput("Please input the Start Node ");
            end = Network::getInstance()->askNodesInput("Please input the End Node ");
            Network::getInstance()->getNetwork()->edmondKarpFlux(start,end);
            sleep(4);
            break;
        case '4':
            start = Network::getInstance()->askNodesInput("Please input the Start Node ");
            end = Network::getInstance()->askNodesInput("Please input the End Node ");
            Network::getInstance()->getNetwork()->longestPath(start, end);
            sleep(4);
            break;
        case '5':
            start = Network::getInstance()->askNodesInput("Please input the Start Node ");
            end = Network::getInstance()->askNodesInput("Please input the End Node ");
            Network::getInstance()->getNetwork()->node_wait_times(start,end);
            break;
        case 'h':
            display_scen2_description();
            sleep(4);
            break;
        case '0': {
            Network::getInstance()->setShouldPop(true);
            break;
        }
        default: std::cout << "Invalid Input \n:";
            system("pause");
    }

}