/**
 * @file main.cpp
 * This main function is used to test the graph ADT based on a simple 5*5 gridGraph.
 * @date May 2021
 * @author
 */

#include "RealGraph.h"
#include <iostream>
using namespace std;

/**
 * * (Hins) This main function is used to test the graph ADT based on a simple 5*5 gridGraph
 * * Comment it and use the other main function when we actually read the data and run our executable 
 */
int main()
{
    GraphMatrix<string, string> g = GraphMatrix<string, string>();
    gridGraph(g, 5, 5);

    /**
     * * Tests for graph data structure (i.e., V and E). We need to switch V and E to public members
     */

    /**
     * Test V
     * TODO: Checked
     */
    string test_V;
    for (auto i: g.V)
    {
        test_V += i.data + "-";
    }
    cout << "====================================" << endl;
    cout << "Test V" << endl;
    cout << test_V << endl;
    cout << "====================================" << endl;


    /**g.
     * * Tests for vertex-related members
     */

    /**
     * insert
     * TODO: Checked
     */
    int test_insert_v = g.insert("25");
    cout << "====================================" << endl;
    cout << "Test insert vertex" << endl;
    cout << "The index of the inserted vertex 25 is: " << test_insert_v << endl;
    cout << "====================================" << endl;


    /**
     * remove
     * TODO: Checked
     */
    g.remove(24);
    int test_remove_v = g.E[0].size();
    cout << "====================================" << endl;
    cout << "Test remove vertex" << endl;
    cout << "The size of the adjacency matrix after removal of vertex 24 is: " << test_remove_v << " because we insert a vertex 25 at last test." << endl;
    cout << "====================================" << endl;

    /**
     * vertex
     * TODO: Checked
     */
    string test_vertex_name = g.vertex(6);
    cout << "====================================" << endl;
    cout << "Test vertex" << endl;
    cout << "The name of vertex 6 is: " << test_vertex_name << endl; 
    cout << "====================================" << endl;


    /**
     * inDegree
     * TODO: Checked
     */
    int test_indegree = g.inDegree(23);
    cout << "====================================" << endl;
    cout << "Test inDegree" << endl;
    cout << "The indegree of vertex 23 is: " << test_indegree << endl;
    cout << "====================================" << endl;

    /**
     * outDegree
     * TODO: Checked
     */
    int test_outdegree = g.outDegree(25);
    cout << "====================================" << endl;
    cout << "Test outDegree" << endl;
    cout << "The outdegree of vertex 25 is: " << test_outdegree << endl;
    cout << "====================================" << endl;


    /**
     * firstNbr
     * TODO: Checked
     */
    int test_firstNbr = g.firstNbr(2);
    cout << "====================================" << endl;
    cout << "Test firstNbr" << endl;
    cout << "The first neighbor of vertex 2 is: " << test_firstNbr << endl;
    cout << "====================================" << endl;

    /**
     * nextNbr
     * TODO: Checked
     */
    int test_nextNbr = g.nextNbr(1, 5);
    cout << "====================================" << endl;
    cout << "Test nextNbr" << endl;
    cout << "The next neighbor w.r.t to vertex 5 of vertex 1 is: " << test_nextNbr << endl;
    cout << "====================================" << endl;

    /**
     * status (the enum list in c++ will be converted to ascending integer when compile)
     * TODO: Checked
     */
    VStatus test_status = g.status(10);
    cout << "====================================" << endl;
    cout << "Test status" << endl;
    cout << "The status of vertex 10 is: " << test_status << endl;
    cout << "====================================" << endl;

    /**
     * parent, priority, dTime, and fTime are helpers for functions.
     * TODO: NOT need to be tested
     */


    /**
     * * Tests for edge-related members
     */
    
    /**
     * exists
     * TODO: Checked
     */
    bool test_exists = g.exists(0, 6);
    cout << "====================================" << endl;
    cout << "Test exisits" << endl;
    cout << "Does vertex 0 point to vertex 6? " << test_exists << endl;
    cout << "====================================" << endl;

    /**
     * insert
     * TODO: Checked
     */
    g.insert("1->24", 3, 1, 24);
    int test_insert_e = g.outDegree(1);
    cout << "====================================" << endl;
    cout << "Test insert edge" << endl;
    cout << "The outDegree of vertex 1 after inserting an edge 1->25 is: " << test_insert_e << endl;
    cout << "====================================" << endl;

    /**
     * remove
     * TODO: Checked
     */
    g.remove(1, 24);
    g.remove(24, 1);
    int test_remove_e = g.outDegree(1);
    cout << "====================================" << endl;
    cout << "Test remove edge" << endl;
    cout << "The outDegree of vertex 1 after deleting 1->24 is: " << test_remove_e << endl;
    cout << "====================================" << endl;

    /**
     * type (the enum list in c++ will be converted to ascending integer when compile)
     * TODO: Checked
     */
    cout << "====================================" << endl;
    cout << "Test type" << endl;
    EType test_type = g.type(0, 1);
    cout << "The type of edge 0-1 is: " << test_type << endl;
    cout << "====================================" << endl;

    /**
     * edge
     * TODO：Checked
     */
    cout << "====================================" << endl;
    cout << "Test edge" << endl;
    string test_edge_name = g.edge(2, 7);
    cout << "The name of edge 2->7 is: " << test_edge_name << endl; 
    cout << "====================================" << endl;

    /**
     * weight
     * TODO: Checked
     */
    cout << "====================================" << endl;
    cout << "Test weight" << endl;
    int test_weight = g.weight(12, 11);
    cout << "The weight of edge 12-11 is: " << test_weight << endl;
    cout << "====================================" << endl;


    /**
     * * Tests for algorithms
     */
    GraphMatrix<string, string> G = GraphMatrix<string, string>();
    gridGraph(G, 3, 3);

    /**
     * dfs
     * ! Wrong
     */
    // G.dfs(0);

    /**
     * bfs
     * ! Wrong
     */
    // G.bfs(0);

    /**
     * dijkstra
     * Design a shortest path by modifying some weights
     * TODO: Checked
     */
    G.weight(0, 1) = 0.5;
    G.weight(1, 4) = 0.5;
    G.weight(4, 5) = 0.5;
    G.weight(5, 8) = 0.5;
    vector<int> path = G.dijkstra(0, 8);
    string test_dijkstra;
    for (auto i:path)
    {
        test_dijkstra += to_string(i);
    }
    cout << "====================================" << endl;
    cout << "Test dijkstra" << endl;
    cout << "The shortest path should be: " << test_dijkstra << endl;
    cout << "====================================" << endl;


    /**
     * prim
     * TODO: Checked
     */
    G.weight(4, 3) = 0.5;
    G.weight(3, 6) = 0.5;
    G.weight(1, 2) = 0.5;
    G.weight(4, 7) = 0.5;
    G.prim(0);
    string test_prim;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (G.exists(i, j) && G.type(i, j) == TREE)
            {
                test_prim += G.edge(i, j) + "   ";
            }
        }
    }
    cout << "====================================" << endl;
    cout << "Test prim" << endl;
    cout << "All edges of the MST should be: " << test_prim << endl;
    cout << "====================================" << endl;

    /**
     * tsp
     * TODO:
     */
    vector<int> S = {0, 1, 3, 4};
    int s = 0;
    G.tsp(S, s);
    
    return 0;
}