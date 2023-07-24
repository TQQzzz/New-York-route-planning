/**
 * @file Edge.h
 * This header file contains the definition of Edge. It has several attributes: data, weight, type. It will be used in Graph.h and GraphMatrix.h.
 * @date May 2021
 * @author
 */

#pragma once

template <typename Te>
struct Edge
{
    Te data;
    double weight;
    EType type;
    Edge(Te const &d, int w) : data(d), weight(w), type(UNDETERMINED) {}
};