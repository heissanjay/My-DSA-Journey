// Adjacency Matrix representation of Graph

#include <iostream>
using namespace std;

class Graph
{
private:
    bool **adjacencyMatrix;
    int numOfVertices;

public:
    // initializing all the values of the Adjacency Matrix to Zero (0)
    Graph(int numOfVertices)
    {
        this->numOfVertices = numOfVertices;
        adjacencyMatrix = new bool *[numOfVertices];

        for (int i = 0; i < numOfVertices; i++)
        {
            adjacencyMatrix[i] = new bool[numOfVertices];
            for (int j = 0; j < numOfVertices; j++)
            {
                adjacencyMatrix[i][j] = false;
            }
        }
    }
};