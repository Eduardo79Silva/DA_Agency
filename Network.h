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
    string filepath;
    int nodes;
    int edges;
    //vector<vector<int>> graphInfo;  //vetor de dentro tem os 4 int da info do ficheiro
    Graph network = Graph(0, true);

public:
    Network(string filestring);
    void readInfo();
    Graph networkGraph();
    //Graph toGraph();


};


#endif //DA_TRAVEL_NETWORK_H
