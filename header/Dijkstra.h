#ifndef __DIJKSTRA
#define __DIJKSTRA

#include "default.h"

using namespace std;

class Edge{
public:
    int dest;
    int weight;
    Edge(const int& dest, const int& weight):dest(dest), weight(weight){};
    ~Edge(){};
};

class Graph{
private:
    int V;
    int E;
    unordered_map<int, vector<Edge>> adjList;
public:
    Graph():V(0), E(0), adjList({}){};
    ~Graph(){};
    bool addVertex(const int& name);
    bool addEdge(const int& name, Edge& newedge);
    bool addEdge(const int& name, const int& dest, const int& weight);
    inline int getV() const;
    inline int getE() const;
    int getWeight(const int& src, const int& dest);
    bool alterWeight(const int& src, const int& dest, const int& weight);
    vector<int>& getNeighbors(const int& src);
    Graph& buildGraphFromtxt(const string& filePath);
};

#endif