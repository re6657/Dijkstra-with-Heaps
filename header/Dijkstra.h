#ifndef __DIJKSTRA
#define __DIJKSTRA

#include "default.h"

using namespace std;

class Edge{
public:
    int dest;
    int weight;
    Edge(int& dest, int& weight):dest(dest), weight(weight){};
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
    bool addVertex(int& name);
    bool addEdge(int& name, Edge& newedge);
    bool addEdge(int& name, int& dest, int& weight);
    inline int getV() const;
    inline int getE() const;
    int getWeight(int& src, int& dest);
    bool alterWeight(int& src, int& dest, int& weight);
    vector<int>& getNeighbors(int& src);
    Graph& buildGraphFromtxt(const string& filePath);
};

#endif