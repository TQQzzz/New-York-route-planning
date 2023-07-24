/**
 * @file Graph_prim.h
 * This file defines Prim's algorithm. 
 * Prim's (also known as Jarník's) algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. 
 * This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized. 
 * @date May 2021
 * @author
 */

#pragma once

template <typename Tv, typename Te>
void Graph<Tv, Te>::prim(int s)
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
            if ((status(j) == UNDISCOVERED) && (priority(j) > weight(s, j)))
            {
                priority(j) = weight(s, j);
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
}