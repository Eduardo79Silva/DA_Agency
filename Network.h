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
    //vector<vector<int>> graphInfo;  //vetor de dentro tem os 4 int da info do ficheiro


public:
    static Network * getInstance();
    void readInfo();
    Graph *  readGraph();
    void readData(const string& filestring);
    //Graph toGraph();


    void setShouldPop(bool b) {
        this->should_Pop = b;
    }

    bool getShouldPop() {
        return this->should_Pop;
    }

    int askNodesInput(const string& message) {
        int input;
        int n = network->getNodes().size();

        bool validInput = true;
        do
        {
            cout << message;

            cin >> input;

            if (input < 1 || input > n || cin.fail())
            {
                cout << "Invalid!" << endl;

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
