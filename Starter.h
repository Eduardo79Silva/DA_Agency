//
// Created by zediogo96 on 30/05/22.
//

#ifndef DA_TRAVEL_STARTER_H
#define DA_TRAVEL_STARTER_H


#include <stack>

#include "Menu.h"
#include "Network.h"

using namespace std;

/**
 * @brief Class that facilitates the start of our program
 */
class Starter {

private:

    Network * application;
    stack<Menu*> menuStack;

public:

    /**
     * @brief Default constructor that pushed the Main Menu to the stack
     *
     */
    Starter();

    /**
     * @brief Starts the application loop, loads all the data from the files to application before
     *
     */
    void start();

};


#endif //DA_TRAVEL_STARTER_H
