/**
 * @file GraphMatrix.h
 * It is the matrix implementation of the graph. Its properties are inherited from Graph.h.
 * We use this file to store data through graph.
 * @date May 2021
 * @author
 */

#pragma once
#include "Graph.h"
#include <iostream>
using namespace std;



template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>
{
    // (Hins) Since our base class is template class, the derived class GraphMarix don't know how to access n and e
    // Therefore, we need to add these two lines.
    using Graph<Tv, Te>::n;
    using Graph<Tv, Te>::e;
private:

public:
    vector<Vertex<Tv>> V;
    vector<vector<Edge<Te>*>> E;
    
    GraphMatrix(){}
    ~GraphMatrix()
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

                delete E[j][k];
            }
                
        }
    }

    virtual Tv &vertex(int i) { return V[i].data; }
    virtual int inDegree(int i) { return V[i].inDegree; }
    virtual int outDegree(int i) { return V[i].outDegree; }
    virtual int firstNbr(int i) { return nextNbr(i, n); }
    virtual int nextNbr(int i, int j)
    {
        while ((-1 < j) && !(exists(i, --j))) {}
        return j;
    }

    virtual VStatus &status(int i) { return V[i].status; }
    virtual int &dTime(int i) { return V[i].dTime; }
    virtual int &fTime(int i) { return V[i].fTime; }
    virtual int &parent(int i) { return V[i].parent; }
    virtual int &priority(int i) { return V[i].priority; }

    virtual int insert(Tv const &vertex)
    {
        for (int j = 0; j < n; j++) 
        {
            E[j].push_back(NULL);
        }
        n++;
        vector<Edge<Te>*> tmp_vec(n, NULL);
        E.push_back(tmp_vec);
        V.push_back(Vertex<Tv>(vertex));
        return n - 1;
    }

    virtual void remove(int i)
    {
        for (int j = 0; j < n; j++)
        {
            if (exists(i, j))
            {
                delete E[i][j];
                E[i][j] = NULL;
                V[j].inDegree--;
                e--;
            }
        }

        E.erase(E.begin() + i);
        n--;
        Tv data = vertex(i);
        V.erase(V.begin() + i);

        for (int j = 0; j < n; j++)
        {
            if (exists(j, i))
            {
                delete E[j][i];
                E[j][i] = NULL;
                V[j].outDegree--;
                e--;
            }
            E[j].erase(E[j].begin() + i);
        }
    }

    virtual bool exists(int i, int j)
    {
        return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
    }

    virtual EType &type(int i, int j) { return E[i][j]->type; }
    virtual Te &edge(int i, int j) { return E[i][j]->data; }
    virtual double &weight(int i, int j) { return E[i][j]->weight; }

    virtual void insert(Te const &edge, int w, int i, int j)
    {
        if (exists(i, j))
        {
            return;
        }
        E[i][j] = new Edge<Te>(edge, w);
        e++;
        V[i].outDegree++;
        V[j].inDegree++;
    }

    virtual void remove(int i, int j)
    {
        if (!exists(i, j))
        {
            return;
        }
        Te data = edge(i, j);
        delete E[i][j];
        E[i][j] = NULL;
        e--;
        V[i].outDegree--;
        V[j].inDegree--;
    }
};