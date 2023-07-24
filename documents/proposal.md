# Final Project Proposal

## Background and Leading Question
Graph theory and graph algorithms have countless applications. Our group is interested in the most natural but almost the most popular one - city transportation network. Particularly, road network and its associated transportation problems are of our concern. Our ultimate goal is to develop a general search tool that can accomplish two tasks based on a given dataset of a road network. These two tasks are elaborated as follows:

+ __Shortest Path Problem:__ Given two nodes A and B in a graph, which correspond to two locations in the city road network, our tool can compute the shortest path from A to B.

+ __Traveling Salesman Problem (TSP):__ Given a set of nodes S = {I_1, I_2, ..., I_N} and a central node I_0 in a graph, which correspond to a set of locations in the city road network, our tool can compute the most efficient route that starts from node I_0, visit all nodes in S for one and only one time, and return to node I_0.

Due to the level and time restrictions of cs225 project, our tool is illustrative only and cannot be comparable with any commercial software for navigation and/or logistics analysis. Those tool consider more factors (e.g., traffic and time windows) and utilize much more complex algorithms.

## Dataset Acquisition and Processing
Out of all big cities in the world, New York is almost the one with largest amount of groud transportaton data. NYC open data is an excellent public data set that can provide us all versions and formats of road network data. The access point of this data set is here: https://opendata.cityofnewyork.us/. There are also other sources to access the road network data of NYC like https://www1.nyc.gov/site/planning/data-maps/open-data/dwn-lion.page. Note that no matter what source we use, the data set is basically the same they are standardized by GIS people.

The original dataset is in the format of shape file (i.e., .shape). We need to input those file into the GIS software (e.g., ArchGis) or use one of those APIs to process it into two csv files. The first csv file of nodes consists of three columns. They are _latitude_, _longitude_, and _index_. The second csv file consists of a companion matrix recording the pairwise distance of nodes. Note that this matrix is sparse since each node in a city road network is connected to most 4 to 5 nodes in its neighborhood.

The whole dataset of NYC containing all levels of roads is too large since lack of hardware acceleration may prevent us from actually running the algorithms. Therefore, we will extract a subset of data for illustration.

## Graph Algorithms
There are totally two concrete algorithms we need to implement in additional to the part of constructing a graph data structure from a real-world data set, which is the construction algorithm.

+ __Construction Algorithm:__ This is the basic component in our code that takes the road network data and transform it into a graph data structure used in advanced algorithms later. The _input_ is a csv file described in thes section of dataset. The _output_ is the graph data structure stored in the heap memory. 

+ __Dijkstra Algorithm:__ Theoretically, it is the most efficient algrorithm to exactly solve the shortest path problem give that all weights of the network is positive. Obviously, weights of road network are the distances between node pairs. If Fibonacci heap is used for optimization, its time complexity is O(E + V log V) where E is the number of edges and V is the number of nodes. The _input_ are the graph itself and two nodes A and B. The _ouput_ is a path from A to B. Note that dijkstra algorithm implicitly traverses the whole graph.

+ __A Star Algorithm (Optional):__ It is an efficient heuristic algorithm for the shortest path problem and may be the most efficient in practice when exact solution is not required. The _input_ and _output_ are the same with dijkstra algorithm.

+ __Minimum Spanning Tree (MST) -Based Heuristic Algorithm (Optional):__ Note that TSP is an extensively-studied NP-hard problem. Therefore, we choose an efficient heuristic algorithm to solve it and the heuristic does not involve additional parameters to tune (The heuristic comes from the random choice of the initial node). The time complexity is O(V^2). The _input_ are the graph itself, a set of nodes S to visit, and a central node I_0. The _output_ is a route starting and ending at I_0 but visit all nodes in the set S for one times. 


## Timeline
The timeline can be divied into four parts corresponding to four and a half weeks we have from now on. During each week, we will work in parallel since tasks are not necessarily solved sequentially. 

__Week 1:__ Data acquisition and processing (Threa 1). Code structure construction (Threa 2).

__Week 2:__ Data acquisition and processing (Threa 1). The construction algorithm by simulated simple data (Thread 2).

__Week 3:__ Dijkstra algorithm and its optimization (Thread 1). A star algorithm (Thread 2). 

__Week 4:__ Minimum Spanning Tree (MST) -Based Algorithms (Thread 1). Writing of report (Thread 2).

__Week 5:__ Wrap up all deliverables and generate a final report (Only three days left in this week).

## Disclaimer
The goal of this project is intentionally set a bit higher than basic requirements, thus all details are subject to change if the attempt is too complex. If that is the case, a simpler alternative that meet the basic requirement will be replaced. 
