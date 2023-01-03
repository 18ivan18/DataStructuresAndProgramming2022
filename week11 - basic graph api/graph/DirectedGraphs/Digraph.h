#ifndef DIGRAPH
#define DIGRAPH
#include <fstream>
#include <list>

class Digraph
{
private:
    std::list<int> *adjacent; // adj[v] = adjacency list for vertex v
    int *indegree_;           // indegree[v] = indegree of vertex v
    int vertices;             // number of vertices in this digraph
    int edges;                // number of edges in this digraph

public:
    Digraph(int);
    Digraph(std::ifstream &);
    Digraph(const Digraph &);
    Digraph &operator=(const Digraph &) = delete;
    int V() const;
    int E() const;
    std::list<int> adj(const int &) const;
    void addEdge(int, int);
    void removeEdge(int, int);
    int indegree(int) const;
    int outdegree(int) const;
    Digraph *reverse();

    ~Digraph();
};

#endif
