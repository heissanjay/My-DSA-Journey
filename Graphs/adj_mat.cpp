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

    // add edge
    void addEdge(int i, int j)
    {
        adjacencyMatrix[i][j] = true;
        adjacencyMatrix[j][i] = true;
    }

    // remove edge
    void removeEdje(int i, int j)
    {
        adjacencyMatrix[i][j] = false;
        adjacencyMatrix[j][i] = false;
    }
    void print_matrix()
    {
        for (int i = 0; i < numOfVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numOfVertices; j++)
                cout << adjacencyMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    // Destructor to delete matrix
    ~Graph()
    {
        for (int i = 0; i < numOfVertices; i++)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }
};
int main(int argc, char const *argv[])
{
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);

    graph.print_matrix();
    return 0;
}
