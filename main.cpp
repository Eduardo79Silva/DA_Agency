#include <iostream>
#include "Network.h"
#include <string>

using namespace std;

int main() {

    int network_number = 1;

    Network networkrep = Network(to_string(network_number));

    Graph network_graph = networkrep.getNetwork();  //graph read working

    cout << endl << endl << endl << endl << endl;

    network_graph.BFS(1,30);  //bfs working





    return 0;
}
