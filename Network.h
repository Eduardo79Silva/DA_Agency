//
// Created by Afonso Martins on 17/05/2022.
//


#ifndef DA_TRAVEL_NETWORK_H
#define DA_TRAVEL_NETWORK_H

#include <string>
#include <fstream>
#include "graph.h"
using namespace std;



class Network {
protected:
    Network();

    static Network * nw;

    Graph * network;

    bool should_Pop;

public:
    Graph * getNetwork() const;

    void operator=(const Network &) = delete;

private:
    string filepath;
    int nodes;
    int edges;


public:
    /**
     * @return An instance of the network class
     */
    static Network * getInstance();
    /**
     * REads the info from the files to the application
     */
    void readInfo();
    /**
     * @return A graph with all the information
     */
    Graph *  readGraph();
    /**
     * Reads data from a file
     * @param filestring The name of the file to read from
     */
    void readData(const string& filestring);


    void setShouldPop(bool b) {
        this->should_Pop = b;
    }

    bool getShouldPop() {
        return this->should_Pop;
    }

    /**
     * Function to ask for input to the user
     * @param message The message to show to the user
     * @return Input from the user
     */
    int askNodesInput(const string& message) {
        int input;
        int n = network->getNodes().size();

        bool validInput = true;
        do
        {
            cout << message << "(between 1 and " << n << "): ";

            cin >> input;

            if (input < 1 || input > n || cin.fail())
            {
                cout << "Error: Invalid node number!" << endl;

                cin.clear();
                cin.ignore();
                validInput = false;
            } else {
                validInput = true;
                return input;
            }
        } while (true);
    }
};

#endif //DA_TRAVEL_NETWORK_H
