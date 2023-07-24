/**
 * @file main.cpp
 * This header file contains the definition of Vertex. It has several attributes: data, inDegree, outDegree, status, priority. It will be used in Graph.h and GraphMatrix.h.
 * @date May 2021
 * @author
 */

#pragma once

template <typename Tv>
struct Vertex
{
    /**
     * ! It means data can only be standard class like int, string, char, double, and so on.
     */
    Tv data; 
    int inDegree, outDegree;
    VStatus status;
    int dTime, fTime;
    int parent;
    int priority;

    // Tv(0) means we cast 0 to the type of Tv
    Vertex(Tv const &d = (Tv)0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), 
                                  dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};