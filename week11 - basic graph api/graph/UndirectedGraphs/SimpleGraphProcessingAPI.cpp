#include "SimpleGraphProcessingAPI.h"

int SimpleGraphProcessingAPI::degree(const Graph &G, int v)
{
    return G.adjacent(v).size();
}

int SimpleGraphProcessingAPI::maxDegree(const Graph &G)
{
    int max = 0;
    for (size_t v = 0; v < G.V(); v++)
    {
        if (degree(G, v) > max)
        {
            max = degree(G, v);
        }
    }
    return max;
}

double SimpleGraphProcessingAPI::avgDegree(const Graph &G)
{
    return 2.0 * G.E() / G.V();
}

int SimpleGraphProcessingAPI::numberOfSelfLoops(const Graph &G)
{
    int count = 0;
    for (size_t v = 0; v < G.V(); v++)
    {
        for (int w : G.adjacent(v))
        {
            if (v == w)
            {
                count++;
            }
        }
    }
    return count / 2;
}