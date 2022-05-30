//
// Created by zediogo96 on 30/05/22.
//

#include "Starter.h"
#include "Network.h"

Starter::Starter() {
    application = Network::getInstance();
    menuStack.push(new MainMenu());
}

void Starter::start() {

    while (!menuStack.empty()) {
        menuStack.top()->display();

        if (menuStack.top()->getNextMenu() != nullptr) {
            Menu * tmp = menuStack.top()->getNextMenu();
            menuStack.top()->setNextMenu(nullptr);
            menuStack.push(tmp);
        }
        else {
            delete menuStack.top();
            menuStack.pop();
        }
    }
}