#ifndef __DIJKSTRA
#define __DIJKSTRA

#include "default.h"

using namespace std;

struct Edge{
    string dest;
    int weight;
};

class Graph{
private:
    int V;
    int E;
    unordered_map<string, vector<Edge>> adjList;
public:
    Graph();
    ~Graph();
};

#endif