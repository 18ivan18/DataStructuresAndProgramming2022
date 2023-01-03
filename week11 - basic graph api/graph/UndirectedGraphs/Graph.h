#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH
#include <fstream>
#include <list>

class Graph
{
private:
    std::list<int> *adj;
    int vertices;
    int edges;

public:
    Graph(int);
    Graph(std::ifstream &);
    Graph(const Graph &) = delete;
    Graph &operator=(const Graph &) = delete;
    ~Graph();

    void addEdge(int, int);
    // void removeEdge(int, int);
    std::list<int> adjacent(int) const;
    friend std::ostream &operator<<(std::ostream &, const Graph &);

    int V() const;
    int E() const;
};

#endif
