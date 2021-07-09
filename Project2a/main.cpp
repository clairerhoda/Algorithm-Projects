#include "build.cpp" //connection to other cpp file
#include "ngraph.hpp"
using namespace NGraph;

void prim_jarnik(int size, int matrix[20][20], NGraph::Graph graph) {
    std::cout << "~~~~~Minimum Spanning Tree~~~~~~ \n";
    bool myBoolArray[20] = {false}; //used to see if vertex is part of MST
    std::vector<int> MST_verticies;
    MST_verticies.push_back(0); //adds zero as the first element 
    int target_vertex; 
    int smallest_edge = 100;
    int vertex1;
    int vertex2;
    int totalWeight = 0;
    bool check = false;
    while (check == false) {
        for (int i = 0; i < MST_verticies.size(); i ++) { //checks all verticies in MST
            target_vertex = MST_verticies[i];
            Graph::vertex_set So = graph.out_neighbors(target_vertex);
            for (Graph::vertex_set::const_iterator t = So.begin(); t !=So.end(); t++) { //checks edges of focued vertex
                if (matrix[target_vertex][*t] < smallest_edge and myBoolArray[*t] == false) {
                    smallest_edge = matrix[target_vertex][*t];
                    vertex1 = target_vertex;
                    vertex2 = *t;
                }
            }

            Graph::vertex_set Si = graph.in_neighbors(target_vertex);
            for (Graph::vertex_set::const_iterator t = Si.begin(); t !=Si.end(); t++) { //checks edges of focued vertex
                if (matrix[target_vertex][*t] < smallest_edge and myBoolArray[*t] == false) {
                    smallest_edge = matrix[target_vertex][*t];
                    vertex1 = target_vertex;
                    vertex2 = *t;
                }
            }
        }
        std::cout << "Edge: {" << vertex1 << ", " << vertex2 << "} ";
        std::cout << "Weight of Edge: " << matrix[vertex1][vertex2] << "\n";
        myBoolArray[target_vertex] = true;
        myBoolArray[vertex2] = true;
        MST_verticies.push_back(vertex2);
        totalWeight += smallest_edge;
        graph.remove_edge(vertex1, vertex2);
        smallest_edge = 100;
        if (MST_verticies.size() == size)
            check = true;
    }
    std::cout << "Total Weight " << totalWeight << "\n";
}
        


int main() {
    std::cout << "********Problem 6-3(b)********\n\n";
    NGraph::Graph graphA;
    graphA = graph1(); //creates graph for problem 6-3(b)
    prim_jarnik(9, matrixA, graphA); //builds minimum spanning tree 
    std::cout << "\n";
    std::cout << "********Problem 6-3(c)********\n\n";
    NGraph::Graph graphB;
    graphB = graph2(); //creates graph for problem 6-3(c)
    prim_jarnik(7, matrixB, graphB); //builds minimum spanning tree 
    return 0;
}

