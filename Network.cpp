//
// Created by Afonso Martins on 17/05/2022.
//

#include "Network.h"


Network::Network(string filestring){  //file vai ser um número (representado em string)

    //get filepath for the desired network

    string filep;

    if (stoi(filestring)>0 && stoi(filestring)<=9) {
        filep = ".././Tests_B/in0" + filestring + "_b.txt";
    }
    else {
        filep = ".././Tests_B/in" + filestring + "_b.txt";
    }

    filepath = filep;

    //read the info about the network

    readInfo();

    //read the network to the graph

    network = networkGraph();

    //reading to graph completed

}

void Network::readInfo() {

    ifstream file;
    file.open(filepath);
    string nod, edg;
    getline(file, nod, ' ');
    getline(file, edg, '\n');
    int nodeno = stoi(nod);
    this->nodes = nodeno;
    int edgeno = stoi(edg);
    this->edges = edgeno;

}


Graph Network::networkGraph() {

    //vector<vector<int>> info;
    Graph net(nodes, true);

    ifstream file;
    file.open(filepath);
    file.ignore(1000, '\n');

    string origins, destinations, capacitys, durations;
    int origin, destination, capacity, duration;


    while (getline(file, origins, ' ')) {
        getline(file, destinations, ' ');
        getline(file, capacitys, ' ');
        getline(file, durations, '\n');
        origin = stoi(origins);
        destination = stoi(destinations);
        capacity = stoi(capacitys);
        duration = stoi(durations);
        cout << origin << "  -  " << destination << "  -  " << capacity << "  -  " << duration << endl;
        net.addEdge(origin, destination, capacity, duration);  //alterar fields do grafo e métodos
    }

    return net;
}

/*Graph Network::toGraph() {

    Graph (nodes, true);
}*/