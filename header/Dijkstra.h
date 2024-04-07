#ifndef __DIJKSTRA
#define __DIJKSTRA

#include "default.h"
#include "Fib_Heap.h"
#include "Binomial_Queue.h"

using namespace std;

class Edge{
public:
    int dest;
    int weight;
    Edge(const int& dest, const int& weight):dest(dest), weight(weight){};
    ~Edge(){};
};

class Graph{
public:
    int V;
    int E;
    unordered_map<int, vector<Edge>> adjList;
    Graph():V(0), E(0), adjList({}){};
    ~Graph(){};
    bool addVertex(const int& name);
    bool addEdge(const int& name, Edge& newedge);
    bool addEdge(const int& name, const int& dest, const int& weight);
    int getV() const {return V;};
    int getE() const {return E;};
    int getWeight(const int& src, const int& dest);
    bool alterWeight(const int& src, const int& dest, const int& weight);
    const vector<int>& getNeighbors(const int& src);
    const Graph& buildGraphFromtxt(const string& filePath);
};

const int dijkstra(Graph& graph, const int& src, const int& dest, FibHeap& queue);
const int dijkstra(Graph& graph, const int& src, const int& dest, Binomial_Queue& queue);

#endif