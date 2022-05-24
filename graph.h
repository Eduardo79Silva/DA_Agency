// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
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
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        double dist;
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
    void dijkstra(int s);


public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int capacity = 1, int time = 1);

    /**
     * Calcula a menor distância com base no algoritmo de Dijkstra
     * @param a O nó de início
     * @param b O nó de fim
     * @return A menor distância de um nó ao outro
     */
    double dijkstra_distance(int a, int b);
    /**
     * Identifica o menor caminho com base no algoritmo de Dijkstra
     * @param a O nó de início
     * @param b O nó de fim
     * @param linhas Lista que será preenchida com as linhas percorridas no percurso
     * @return Uma lista de inteiros representado os nós percorridos
     */
    list<int> dijkstra_path(int a, int b, list<string>& linhas);

     /**
     * Algoritmo de Breadth First Search entre dois nós
     * @param a O nó de início
     * @param b O nó de fim
     */
    void BFS(int a, int b);
    /**
    * Identifica o melhor caminho tendo em conta o número de nós percorridos, com base no algoritmo de BFS
    * @param a O nó de início
    * @param b O nó de fim
    * @param linhas Lista que será preenchida com as linhas percorridas no percurso
    * @return Uma lista de inteiros representado os nós percorridos
    */
    list<int> BFS_path(int a , int b, list<string>& linhas);

    vector<Node> getNodes() {
        return nodes;
    }


};

#endif
