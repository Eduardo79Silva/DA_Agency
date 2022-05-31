// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include "maxHeap.h"
#include <vector>
#include <list>
#include <iostream>
#include <queue>


using namespace std;

/**
     * Implementação de grafo.
     */

class Graph {
    struct Edge {
        int dest;   // Destination node
        int capacity;
        int time;  // Two integer weights (capacity, time)
        int flow;
        int resCap;
    };

    struct Node {
        int id;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        std::list<Edge> res;  // Residual
        int dist;
        int capacity;
        int pred;
        bool visited;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

    /**
     * Algoritmo de Dijkstra
     * @param s O nó de início
     */



public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int capacity = 1, int flow = 0, int time = 1);

    //to remove
    void print() const;

    void dijkstra(int s);

     /**
     * Algoritmo de Breadth First Search entre dois nós
     * @param a O nó de início
     * @param b O nó de fim
     */
    void BFS(int a, int b);


    vector<Node> getNodes() {
        return nodes;
    }

    void maximumFlowPath(int src);

    vector<int> get_path(int a, int b);

    int path_Capacity(list<int> path);


    int edmondKarpFlux(int start, int end);


    std::pair<int, vector<Graph::Edge>> bfs1(int v, int b);

    void reset_Flux();

    Graph resGraph();
};

#endif
