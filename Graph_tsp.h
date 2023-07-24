/**
 * @file Graph_tsp.h
 * The travelling salesman problem (also called the traveling salesperson problem[1] or TSP) asks the following question: 
 * "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?" 
 * It is an NP-hard problem in combinatorial optimization, important in theoretical computer science and operations research.
 * @date May 2021
 * @author
 */

#pragma once
using namespace std;


// (Hins) This version of construction heuristic is a bit tedious
template <typename Tv, typename Te>
vector<Tv> Graph<Tv, Te>::tsp(vector<int> S, int s)
{
    // (Hins) Extract the subgraph formed by the set of target vertices
    GraphMatrix<Tv, Te> g = subgraph(S);

    // (Hins) Call prim to construct a MST with the source given
    g.prim(s);

    // (Hins) Clean the subgraph with only TREE edges left
    for (int i = 0; i < g.n; i++)
    {
        for (int j = i + 1; j < g.n; j++)
        {
            if (g.exists(i, j) && g.type(i, j) != TREE)
            {
                g.remove(i, j);
            }
            if (g.exists(j, i) && g.type(j, i) != TREE)
            {
                g.remove(j, i);
            }
        }
    }

    // (Hins) Construct a Eulerian tour based on the MST
    g.reset();
    for (int i = 0; i < g.n; i++)
    {
        for (int j = i + 1; j < g.n; j++)
        {
            if (g.exists(i, j))
            {
                g.insert(Te(), 1, j, i);
            }
        }
    }

    // (Hins) Shortcut traversal (based on DFS) to get a valid TSP route
    // (Hins) Abuse FORWARD to represent the actual path and CROSS to represent paths that are short-cut
    vector<Tv> route;
    route.push_back(g.vertex(s));
    g.status(s) == DISCOVERED;
    int edge_counter = 0;

    while (edge_counter < g.e)
    {
        for (int u = firstNbr(s); u > -1; u = nextNbr(s, u))
        {
            if (g.type(s, u) != UNDETERMINED)
            {
                continue;
            }

            if (g.status(u) == DISCOVERED)
            {
                g.type(u) == CROSS;
                edge_counter++;
                s = u;
            }
            else if (g.status(u) != DISCOVERED)
            {
                g.status(u) == DISCOVERED;
                g.type(s, u) == FORWARD;
                edge_counter++;
                s = u;
                route.push_back(g.vertex(s));
                break;
            }
        }
    }

    // (Hins) At this moment, the TSP route should go back to its departure
    route.push_back(g.vertex(s));
    return route;
}


// (Hins) At this moment, we can only input indices of the vertex in the original graph
// (Hins) Need further improvement such that input of names of vertices can work
template <typename Tv, typename Te>
Graph<Tv, Te> Graph<Tv, Te>::subgraph(vector<int> S)
{
    Graph sub = Graph();
    for (auto i: S)
    {
        for (auto j: S)
        {
            if (i == j)
            {
                continue;
            }

            if (exists(i, j))
            {
                int id1 = insert(vertex(i));
                int id2 = insert(vertex(j));
                insert(weight(i, j), id1, id2);
            }
        }
    }
    return sub;
}
