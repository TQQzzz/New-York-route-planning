/**
 * @file GraphAdjList.h
 * It is the Adjacency Lsit implementation of the graph
 * (Hins) At this moment, we GAVE UP this implementation and give priority to other tasks.
 * @date May 2021
 * @author
 */

#pragma once
#include "Graph.h"
#include <algorithm>
#include <unordered_set>
#include <map>
#include <iostream>
#include <vector>
using namespace std;





template <typename Tv,typename Te>
class GraphAdjList : public Graph<Tv, Te>
{
private:
    vector<vertex<Tv>> V;
    vector<vector<Edge<Te> *>> E;
    list<int> *adjLists;


public:
    GraphAdjlist();
    ~GraphAdjList();//(tqian3) constructer?de?
    // (Hins) This is a destructor.
    
    virtual Tv &vertex(int i) { return V[i].data; }
    virtual int inDegree(int i) { return V[i].inDegree; }
};