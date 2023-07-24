/**
 * @file RealGraph.h
 * This file include functions that can actually build a real graph.
 * We have a grid-like directed graph with h*w vertices to test whether our graph implement is correct.
 * @date May 2021
 * @author
 */

#pragma once
#include "GraphMatrix.h"
#include <string>
using namespace std;
 
/**
 * TODO: Complete a function to generate a random graph
 */
template <typename Tv, typename Te>
void randomGraph(GraphMatrix<Tv, Te> & graph, int n, int e, double prob_v, double prob_e)
{
}

/**
 * A grid-like directed graph with h*w vertices
 */
template <typename Tv, typename Te>
void gridGraph(GraphMatrix<Tv, Te> & graph, int h, int w)
{
    int index;
    string c, c_left, c_up;
    // (Hins) Insert vertices and horizontal edges
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // (Hins) The unique index for vertices
            index = i * w + j;
            c = to_string(index);
            graph.insert(c);
            
            if (j > 0)
            {
                c_left = to_string(index - 1);
                graph.insert(c_left + "->" + c, 1, index-1, index);
                graph.insert(c + "->" + c_left, 1, index, index-1);
            }
        }
    }

    // (Hins) Insert vertical edges
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < h; i++)
        {
            if (i > 0)
            {
                index = i * w + j;
                c = to_string(index);
                c_up = to_string(index - w);
                graph.insert(c_up + "->" + c, 1, index - w, index);
                graph.insert(c + "->" + c_left, 1, index, index -w);
            }
        }
    }
}


/**
 * TODO: Complete a function to read a csv file to construct a graph
 */
template <typename Tv, typename Te>
void importGraph(GraphMatrix<Tv, Te> & graph)
{
}


