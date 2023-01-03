#ifndef SIMPLE_GRAPH_PROCESSING_API
#define SIMPLE_GRAPH_PROCESSING_API

#include "Graph.cpp"

class SimpleGraphProcessingAPI
{
public:
    SimpleGraphProcessingAPI() = delete;
    static int degree(const Graph &, int);
    static int maxDegree(const Graph &);
    static double avgDegree(const Graph &);
    static int numberOfSelfLoops(const Graph &);
};

#endif
