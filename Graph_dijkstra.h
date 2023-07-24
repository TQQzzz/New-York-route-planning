/**
 * @file Graph_dijkstra.h
 * This file defines Dijkstra Algorithm.
 * Theoretically, it is the most efficient algrorithm to exactly solve the shortest path problem give that all weights of the network is positive.
 * @date May 2021
 * @author
 */

#pragma once
#include <iostream>
using namespace std;

// (Hins) Need to modify to the version that can return the path and the length
// (Hins) This function seems to be wrong: need to replace all s in the for loop to i
template <typename Tv, typename Te>
vector<int> Graph<Tv, Te>::dijkstra(int s, int t)
{
    reset();
    priority(s) = 0;
    for (int i = 0; i < n; i++)
    {
        status(s) = VISITED;
        if (-1 != parent(s))
        {
            type(parent(s), s) = TREE;
        }

        for (int j = firstNbr(s); - 1 < j; j = nextNbr(s, j))
        {
            if ((status(j) == UNDISCOVERED) && (priority(j) > priority(s) + weight(s, j)))
            {
                priority(j) = priority(s) + weight(s, j);
                parent(j) = s;
            }
        }

        for (int shortest = INT_MAX, j = 0; j < n; j++)
        {
            if ((status(j) == UNDISCOVERED) && (shortest > priority(j)))
            {
                shortest = priority(j);
                s = j;
            }
        }
    }

    int &tmp1 = parent(t);
    int cur = tmp1;
    vector<int> vec;
    vec.insert(vec.begin(), t);
    while (cur != -1)
    {
        vec.insert(vec.begin(), cur);
        int &tmp2 = parent(cur);
        cur = tmp2;
    }

    double L = 0;
    for (int i = 0; i < (int)vec.size()-1; i++)
    {
        L += weight(vec[i], vec[i+1]);
    }
    vec.push_back(L);

    return vec;
}