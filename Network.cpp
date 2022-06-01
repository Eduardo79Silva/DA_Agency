//
// Created by Afonso Martins on 17/05/2022.
//

#include "Network.h"

Network::Network() = default;

Network* Network::nw = nullptr;

Network *Network::getInstance() {
    if (nw == nullptr) nw = new Network();
    return nw;
}

void Network::readData(const string& filestring) {

    (stoi(filestring)>=0 && stoi(filestring)<=9) ? filepath = ".././Tests_B/in0" + filestring + "_b.txt" : ".././Tests_B/in" + filestring + "_b.txt";
    readInfo();
    network = readGraph();
}

void Network::readInfo() {
    ifstream file;
    file.open(filepath);
    string nod, edg;
    getline(file, nod, ' ');
    getline(file, edg, '\n');
    int node_no = stoi(nod);
    this->nodes = node_no;
    int edge_no = stoi(edg);
    this->edges = edge_no;
}

Graph * Network::readGraph() {

    //vector<vector<int>> info;
    auto * net = new Graph(nodes, true);

    ifstream file;
    file.open(filepath);
    file.ignore(1000, '\n');

    string origins, destinations, capacities, durations;
    int origin, destination, capacity, duration;


    while (getline(file, origins, ' ')) {
        getline(file, destinations, ' ');
        getline(file, capacities, ' ');
        getline(file, durations, '\n');
        origin = stoi(origins);
        destination = stoi(destinations);
        capacity = stoi(capacities);
        duration = stoi(durations);
        //cout << origin << "  -  " << destination << "  -  " << capacity << "  -  " << duration << endl;
        net->addEdge(origin, destination, capacity,0, duration, capacity);  //alterar fields do grafo e métodos
    }

    return net;
}

Graph * Network::getNetwork() const {
    return network;
}
