#include "ngraph.hpp"
using namespace NGraph;

int matrixA[20][20]; //initially set to 0
int matrixB[20][20]; //initially set to 0

void display_matrix(int size, int matrix[20][20]) {
   int i, j;
   std::cout << "Weight Matrix \n";
   for(i = 0; i < size; i++) {
      for(j = 0; j < size; j++) {
         std::cout << matrix[i][j] << " ";
      }

    std::cout << '\n';
    }

    std::cout << '\n';
}

NGraph::Graph graph1 () {
    Graph A;
    A.set_undirected();
    A.insert_undirected_edge(6, 7);
    matrixA[6][7] = 4; matrixA[7][6] = 4;
    A.insert_undirected_edge(6, 3);
    matrixA[6][3] = 6; matrixA[3][6] = 6;
    A.insert_undirected_edge(7, 4);
    matrixA[7][4] = 4; matrixA[4][7] = 4;
    A.insert_undirected_edge(7, 8);
    matrixA[7][8] = 6; matrixA[8][7] = 6;
    A.insert_undirected_edge(8, 5);
    matrixA[8][5] = 2; matrixA[5][8] = 2;
    A.insert_undirected_edge(3, 4);
    matrixA[3][4] = 7; matrixA[4][3] = 7;
    A.insert_undirected_edge(3, 0);
    matrixA[3][0] = 3; matrixA[0][3] = 3;
    A.insert_undirected_edge(4, 1);
    matrixA[4][1] = 7; matrixA[1][4] = 7;
    A.insert_undirected_edge(4, 5);
    matrixA[4][5] = 4; matrixA[5][4] = 4;
    A.insert_undirected_edge(5, 2);
    matrixA[5][2] = 2; matrixA[2][5] = 2;
    A.insert_undirected_edge(0, 1);
    matrixA[0][1] = 2; matrixA[1][0] = 2;
    A.insert_undirected_edge(1, 2);
    matrixA[1][2] = 2; matrixA[2][1] = 2;

    display_matrix(9, matrixA);
    // std::cout << "Graph has " << A.num_vertices() << " vertices and " << A.num_edges() << " edges.\n";
    
    int iteration = 0;

    for ( Graph::const_iterator p = A.begin(); p != A.end(); p++) {
        // identify its neighbors
        Graph::vertex_set So = A.out_neighbors(p);
        // print out each out-going edge
        std::cout << "Vertex: " << iteration << '\n';
        for (Graph::vertex_set::const_iterator t = So.begin(); t !=So.end(); t++)
        {
            std::cout << "Edge: {" << iteration << ", " << *t << "} ";
            std::cout << "Weight of Edge: " << matrixA[iteration][*t] << "\n";
        }
        Graph::vertex_set Si = A.in_neighbors(p);
        for (Graph::vertex_set::const_iterator t = Si.begin(); t !=Si.end(); t++)
        {
            std::cout << "Edge: {" << iteration << ", " << *t << "} ";
            std::cout << "Weight of Edge: " << matrixA[iteration][*t] << "\n";
        }

        iteration++;
   }

   std::cout << '\n';
   return A;
}

NGraph::Graph graph2 () {
    Graph B;
    B.set_undirected();
    B.insert_undirected_edge(0, 1);
    matrixB[0][1] = 11; matrixB[1][0] = 11;
    B.insert_undirected_edge(0, 2);
    matrixB[0][2] = 2; matrixB[2][0] = 2;
    B.insert_undirected_edge(0, 3);
    matrixB[0][3] = 10; matrixB[3][0] = 10;
    B.insert_undirected_edge(0, 5);
    matrixB[0][5] = 9; matrixB[5][0] = 9;
    B.insert_undirected_edge(1, 3);
    matrixB[1][3] = 5; matrixB[3][1] = 5; 
    B.insert_undirected_edge(1, 4);
    matrixB[1][4] = 3; matrixB[4][1] = 3; 
    B.insert_undirected_edge(2, 5);
    matrixB[2][5] = 8; matrixB[5][2] = 8; 
    B.insert_undirected_edge(3, 4);
    matrixB[3][4] = 6; matrixB[4][3] = 6; 
    B.insert_undirected_edge(3, 5);
    matrixB[3][5] = 13; matrixB[5][3] = 13; 
    B.insert_undirected_edge(3, 6);
    matrixB[3][6] = 7; matrixB[6][3] = 7; 
    B.insert_undirected_edge(4, 6);
    matrixB[4][6] = 12; matrixB[6][4] = 12; 
    B.insert_undirected_edge(5, 6);
    matrixB[5][6] = 4; matrixB[6][5] = 4; 
    
    display_matrix(7, matrixB);
   
    int iteration = 0;

    for ( Graph::const_iterator p = B.begin(); p != B.end(); p++) {
        // identify its neighbors
        Graph::vertex_set So = B.out_neighbors(p);
        // print out each out-going edge
        std::cout << "Vertex: " << iteration << '\n';
        for (Graph::vertex_set::const_iterator t = So.begin(); t !=So.end(); t++)
        {
            std::cout << "Edge: {" << iteration << ", " << *t << "} ";
            std::cout << "Weight of Edge: " << matrixA[iteration][*t] << "\n";
        }

        Graph::vertex_set Si = B.in_neighbors(p);
        for (Graph::vertex_set::const_iterator t = Si.begin(); t !=Si.end(); t++)
        {
            std::cout << "Edge: {" << iteration << ", " << *t << "} ";
            std::cout << "Weight of Edge: " << matrixB[iteration][*t] << "\n";
        }

        iteration++;
   }

    std::cout << "\n";
    return B;
}


