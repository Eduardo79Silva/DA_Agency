// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#include "graph.h"
#include <climits>

#define INF (INT_MAX/2)

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int capacity, int time) {
    if (src<0 || src>n || dest<0 || dest>n) return;
    nodes[src].adj.push_back({dest, capacity, time});
    if (!hasDir) nodes[dest].adj.push_back({src, capacity, time});
}


// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO
/*double Graph::dijkstra_distance(int a, int b) {
    dijkstra(a);
    if (nodes[b].dist == INF) return -1;
    double test = nodes[b].dist;
    return nodes[b].dist;
}*/

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
/*list<int> Graph::dijkstra_path(int a, int b, list<string>& linhas) {


    dijkstra(a);
    list<int> path;
    if (nodes[b].dist == INF) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        int currentNode = v;
        v = nodes[v].pred;
        list<Edge> lines = {};
        for (auto it = nodes[v].adj.begin(); it != nodes[v].adj.end(); it++) {
            lines.push_back(*it);
        }

        double shortestDistance = INT_MAX;
        string line;
        for(auto it = lines.begin(); it!=lines.end(); it++){
            if(((it)->weight < shortestDistance) && (it->dest == currentNode)){
                shortestDistance = (it)->weight;
                line = (*it).line;
            }
        }
        linhas.push_front(line);

        nodes[v].adj;

        path.push_front(v);
    }
    return path;
}*/

/*
void Graph::dijkstra(int s) {
    MinHeap<int, double> q(n, -1);
    for (int v=1; v<=n; v++) {
        nodes[v].dist = INF;
        q.insert(v, INF);
        nodes[v].visited = false;
    }
    nodes[s].dist = 0;
    q.decreaseKey(s, 0);
    nodes[s].pred = s;
    while (q.getSize()>0) {
        int u = q.removeMin();
        //cout << "Node " << u << " with dist = " << nodes[u].dist << endl;
        nodes[u].visited = true;
        for (auto e : nodes[u].adj) {
            double v = e.dest;
            double w = e.weight;
            if (!nodes[v].visited && nodes[u].dist + w < nodes[v].dist) {
                nodes[v].dist = nodes[u].dist + w;
                q.decreaseKey(v, nodes[v].dist);
                nodes[v].pred = u;
            }
        }
    }
}*/



/*void Graph::BFS(int a, int b) {


    // initialize all nodes as unvisited
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(a);
    nodes[a].dist=0;
    nodes[a].visited=true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        //cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].pred = u;
                nodes[w].visited = true;
                //nodes[w].dist = nodes[u].dist + e.weight;
                nodes[w].dist = nodes[u].dist + 1;
            }
            if(w==b) {
                break;
            }
        }
    }
    cout << endl;

}*/

/*
list<int> Graph::BFS_path(int a, int b, list<string>& linhas) {
    BFS(a,b);
    list<int> path;
    int u = b;

    while (a!=u) {
        int currentNode = u;

        path.insert(path.begin(), u);
        if(u==nodes[u].pred || !(nodes[u].pred>0 && nodes[u].pred<nodes.size())) return {};
        u = nodes[u].pred;
        list<Edge> lines = {};
        for (auto it = nodes[u].adj.begin(); it != nodes[u].adj.end(); it++) {
            lines.push_back(*it);
        }

        double shortestDistance = INT_MAX;
        string line;
        for(auto it = lines.begin(); it!=lines.end(); it++){
            if(((it)->weight < shortestDistance) && (it->dest == currentNode)){
                shortestDistance = (it)->weight;
                line = (*it).line;
            }
        }
        linhas.push_front(line);

    }
    path.insert(path.begin(), a);
    return path;
}*/