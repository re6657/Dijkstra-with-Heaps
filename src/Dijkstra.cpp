#include "default.h"
#include "Dijkstra.h"
#include "Binomial_Queue.h"

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

const vector<int>& Graph::getNeighbors(const int& src)
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

const Graph& Graph::buildGraphFromtxt(const string& filePath)
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

const int dijkstra(Graph& graph, const int& src, const int& dest, FibHeap& queue)
{
    vector<int> dist(graph.getV(), MAX);//2147483647
    vector<bool> visited(graph.getV(), false);
    dist[src] = 0;
    queue.insert(0, src);
    while(!queue.isEmpty())
    {
        int u = 0;
        if(!queue.minimum(&u))
            throw "unable to get minimum";
        queue.removeMin();
        visited[u] = true;
        if(u == dest)
            break;
        for(auto it : graph.adjList[u])
        {
            int v = it.dest;
            int weight = it.weight;
            if(!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                queue.update(v, dist[v]);
            }
        }
    }
    if(dist[dest] == MAX)
    {
        throw "Path Not Found";
    }
    return dist[dest];
}

const int dijkstra(Graph& graph, const int& src, const int& dest, Binomial_Queue& queue)
{
    vector<int> dist(graph.getV(), MAX);//2147483647
    vector<bool> visited(graph.getV(), false);
    dist[src] = 0;
    queue.insert(0, src);
    while(!queue.isEmpty())
    {
        int u = 0;
        if(!queue.minimum(&u))
            throw "unable to get minimum";
        queue.removeMin();
        visited[u] = true;
        if(u == dest)
            break;
        for(auto it : graph.adjList[u])
        {
            int v = it.dest;
            int weight = it.weight;
            if(!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                queue.insert(dist[v], v);
            }
        }
    }
    if(dist[dest] == MAX)
    {
        throw "Path Not Found";
    }
    return dist[dest];
}