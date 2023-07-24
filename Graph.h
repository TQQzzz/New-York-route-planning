/**
 * @file Graph.h
 * Graph.h is the most important file in our project. It shows the ADT of Graph. 
 * It has several functions. The main used are: insert(Tv const &vertex)(insert vertex, and return the current index of that vertex)
remove(int i)(remove vertex and corresponding edges),&vertex(int i)(data of the vertex(existing)),
inDegree(int i)(the number of edges going into vertex V), outDegree(int i)(the number of edges going out of vertex V)
firstNbr(int i)(the first adjacent vertex of V), nextNbr(int i, int j)(the second adjacent vertex of V with an order)
&priority(int i)(the priority series of vertex in traversal tree).

 * @date May 2021
 * @author
 */

#pragma once
#include <stack>
#include <vector>
#include "Tag.h"
using namespace std;


template <typename Tv, typename Te>
class Graph 
{
private:
    void reset() //reset all vertices and edges
    {
        for (int i = 0; i < n; i++) 
        {
            status(i) = UNDISCOVERED;
            dTime(i) = fTime(i) = -1;
            parent(i) = -1;
            priority(i) = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (exists(i, j)) {
                    type(i, j) = UNDETERMINED;
                }
            }

        }
    }
    void BFS(int, int &); // Breadth first search
    void DFS(int, int &); // depth first search    
    
public:

    // Members related to vertices
    int n; // number of vertices
    virtual int insert(Tv const &vertex) = 0; // insert vertex, and return the current index of that vertex
    virtual void remove(int i) = 0; // remove vertex and corresponding edges
    virtual Tv &vertex(int i) = 0; // data of the vertex(existing)
    virtual int inDegree(int i)  = 0; // the number of edges going into vertex V
    virtual int outDegree(int i) = 0; // the number of edges going out of vertex V
    virtual int firstNbr(int i) = 0; // the first adjacent vertex of V
    virtual int nextNbr(int i, int j) = 0; // the second adjacent vertex of V with an order
    virtual VStatus &status(int i) = 0; // the status of the vertex V
    virtual int &parent(int i) = 0; // the parent of vertex V
    virtual int &priority(int i) = 0; // the priority series of vertex in traversal tree
    virtual int &dTime(int i) = 0; // time label dTime of vertex V
    virtual int &fTime(int i) = 0; // time label fTime of vertex V

    // Members related to edges
    int e; // the number of all edges
    virtual bool exists(int i, int j) = 0; // judge whether the edge(u,v) exists
    virtual void insert(Te const &edge, int w, int i, int j) = 0; // insert an edge with w weight between vertex u and vertex v
    virtual void remove(int i, int j) = 0; // remove the edge e between vertex u and v
    virtual EType &type(int i, int j) = 0; // the type of edge(u,v)
    virtual Te &edge(int i, int j) = 0; // the data of edge(u,v)(exsiting) 
    virtual double &weight(int i, int j) = 0; // the weight of edge(u,v)

    // Constructor
    Graph()
    {
        n = 0;
        e = 0;
    }

    // Related algorithms
    void bfs(int);
    void dfs(int);
    void prim(int);
    vector<int> dijkstra(int, int);
    vector<Tv> tsp(vector<int>, int);
    Graph<Tv, Te> subgraph(vector<int>); // find subgraph with given vertices

};


#include "Vertex.h"
#include "Edge.h"
#include "Graph_bfs.h"
#include "Graph_dfs.h"
#include "Graph_prim.h"
#include "Graph_dijkstra.h"
#include "Graph_tsp.h"

