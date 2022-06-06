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
#include <stack>

using namespace std;

/**
 * Graph implementation.
 */

class Graph
{
    struct Edge
    {
        int src;
        int dest; // Destination node
        int capacity;
        int time; // Two integer weights (capacity, time)
        int flow;
        int resCap;
    };

    struct Node
    {
        int id;
        list<Edge> adj;      // The list of outgoing edges (to adjacent nodes)
        std::list<Edge> res; // Residual
        int dist;
        int capacity;
        int pred;
        bool visited;
        int ES;
        int EF;
        int LF;
        int LS;
        int eDeg;
        int sDeg;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

    /**
     * Dijkstra's algorithm
     * @param s Start node
     */

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    /**
     * Add edge from source to destination with corresponding data
     * @param src Source node
     * @param dest Destination node
     * @param capacity Capacity of the connection
     * @param flow Flow in the graph
     * @param time Time of the connection
     * @param resCap Residual capacity in the graph
     */
    void addEdge(int src, int dest, int capacity = 1, int flow = 0, int time = 1, int resCap = 1);

    // to remove
    void print() const;

    /**
     * Dijkstra algorithm from a node
     * @param s The source node
     */
    void dijkstra(int s);

    /**
     * Algoritmo de Breadth First Search entre dois nós
     * @param a O nó de início
     * @param b O nó de fim
     */
    void BFS(int a, int b);

    vector<Node> getNodes()
    {
        return nodes;
    }

    /**
     *  Algorithm to determine the path with maximum flow
     * @param src Start node
     */
    void maximumFlowPath(int src);

    /**
     *
     * @param a Start node
     * @param b End node
     * @param print Indicates if the path should be printed or not
     * @return The path between the two nodes
     */
    vector<int> get_path(int a, int b, bool print);

    /**
     *
     * @param path A path between two nodes
     * @return The capacity of the path
     */
    int path_Capacity(const vector<int> &path);

    /**
     * Edmonds-Karp algorithm between two nodes
     * @param start Start node
     * @param end End node
     * @return The maximum flux
     */
    int edmondKarpFlux(int start, int end);

    bool relax(Node v, Node *w, int weight);

    std::pair<int, vector<Graph::Edge>> bfs1(int v, int b);

    /**
     * Resets the flux in the graph
     */
    void reset_Flux();

    /**
    *
    * @return The residual graph corresponding to the dataset represented in the current graph.
    */
    Graph resGraph();

    /**
    *
    * @param start The node in which the group will start the trip
    * @param end The node in which the group will end the trip
    * @param increment The number of elements to be added to the
    * @param correct Indicates if create group or correct group size
    * @return The difference between the initial flow and the flow considering the new group
    */
    int correctGroupSize(int start, int end, int increment, bool correct);

    /**
     * @return The minimum duration
     */
    int earliestStart();

    /**
     * Calculates the laatest finish time
     */
    void latestFinish(int minDur);

    /**
     * Topological sort
     * @param start Start node
     * @param stack To return the elements in the topological order
     */
    void topSort(int start, std::stack<int> &stack);

    /**
     *
     * @param start Start node
     * @param end End node
     * @return
     */
    int longestPath(int start, int end);

    /**
     * @return The transposition of the current graph
     */
    Graph transposeGraph();

    /**
     * Calculates the waiting times for each node
     * @param start Start node
     * @param end End node
     */
    void node_wait_times(int start, int end);
};

#endif
