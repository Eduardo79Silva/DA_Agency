#include <iostream>
#include "Network.h"
#include <string>

using namespace std;

int main() {

    int network_number = 00;

    Network networkrep = Network(to_string(network_number));

    Graph network_graph = networkrep.getNetwork();  //graph read working

    /*cout << endl << endl << endl << endl << endl;

    network_graph.BFS(1,30);  //bfs working*/

    //network_graph.print();

    //caso 1.1

    int src = 1;
    int dest = 4;

    network_graph.maximumFlowPath(src);
    list<int> path = network_graph.get_path(src, dest);

    network_graph.dijkstra(src);
    path = network_graph.get_path(src, dest);




    return 0;
}
