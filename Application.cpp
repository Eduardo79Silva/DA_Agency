//
// Created by zediogo96 on 30/05/22.
//

#include "Application.h"

Application::Application() = default;

Application* Application::app = nullptr;

/*void Application::loadData() {
    this->packages = getPackagesFromFiles("../input/package.txt");
    this->deliverymans = getDeliveryManFromFiles("../input/carrinhas.txt");
}*/

Application *Application::getInstance() {
    if (app == nullptr) app = new Application();

    return app;
}

