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
};


#endif //DA_TRAVEL_NETWORK_H
