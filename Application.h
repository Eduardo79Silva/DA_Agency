//
// Created by zediogo96 on 30/05/22.
//

#ifndef DA_TRAVEL_APPLICATION_H
#define DA_TRAVEL_APPLICATION_H

#include <algorithm>

#include <cmath>
#include <chrono>
#include <iomanip>

/**
 * @brief Contains the main functionalities needed for the program.
 * All fields are declared under protected since this class is implemented as a Singleton
 */
class Application {

protected:

    /**
     * @brief Default Constructor
     */
    Application();

    static Application * app;
/*
    vector<DeliveryMan> * deliverymans{};

    vector<Package> * packages{};*/

public:

    /**
     * @brief Loads all the data from the input folder to the program
     */
    void loadData();

    void operator=(const Application &) = delete;

    /**
     * @brief Returns a pointer to the Instance object
     *
     * @return Application * instance
     */
    static Application *getInstance();


};



#endif //DA_TRAVEL_APPLICATION_H
