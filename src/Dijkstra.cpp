#include "default.h"
#include "Dijkstra.h"

using namespace std;

bool Graph::addVertex(const int& name)
{
    if(adjList.find(name) != adjList.end())
    {
        throw "Insertion Failed: found element";
        return false;
    }
    adjList[name] = vector<Edge>();
    V++;
    return true;
}

bool Graph::addEdge(const int& name, Edge& newedge)
{
    if(newedge.dest == 0 || newedge.weight == 0)
    {
        throw "Inserted empty edge, operation aborted";
        return true;
    }
    if(adjList.find(name) == adjList.end())
        adjList[name] = vector<Edge>();
    adjList[name].push_back(newedge);
    V++;
    E++;
    return true;
}

bool Graph::addEdge(const int& name, const int& dest, const int& weight)
{
    if(dest == 0 || weight == 0)
    {
        throw "Inserted empty edge, operation aborted";
        return true;
    }
    if(adjList.find(name) == adjList.end())
        adjList[name] = vector<Edge>();
    adjList[name].push_back(Edge(dest, weight));
    V++;
    E++;
    return true;
}

inline int Graph::getV() const
{
    return V;
}

inline int Graph::getE() const
{
    return E;
}

int Graph::getWeight(const int& src, const int& dest)
{
    if(adjList.find(src) == adjList.end())
    {
        throw "Source not found";
        return 0;
    }
    for (Edge& edge : adjList[src])
    {
        if (edge.dest == dest)
            return edge.weight;
    }
    throw "Edge not found";
    return 0;
}

bool Graph::alterWeight(const int& src, const int& dest, const int& weight)
{
    if(adjList.find(src) == adjList.end())
    {
        throw "Source not found";
        return false;
    }
    for (Edge& edge : adjList[src])
    {
        if (edge.dest == dest)
        {
            edge.weight = weight;
            return true;
        }
    }
    throw "Edge not found";
    return 0;
}

vector<int>& Graph::getNeighbors(const int& src)
{
    vector<int> *neighbors = new vector<int>;
    auto it = adjList.find(src);
    if(it != adjList.end())
        for(Edge& edge : it->second)
            (*neighbors).push_back(edge.dest);
    else
    {
        throw "Source not found";
        static vector<int> emptyList;
        return emptyList;
    }
    return *neighbors;
}

Graph& Graph::buildGraphFromtxt(const string& filePath)
{
    ifstream file(filePath);
    string line;
    if(!file.is_open())
    {
        throw "Unable to open .txt file, check your directory";
        static Graph emptyGraph;
        return emptyGraph;
    }
    while(getline(file, line))
    {
        istringstream iss(line);
        int src, dest, weight;
        iss >> src >> dest >> weight;
        addEdge(src, dest, weight);
    }
    return *this;
}