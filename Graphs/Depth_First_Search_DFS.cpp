#include <iostream>
using namespace std;

void print_DFS(bool **edgeMatrix, int vertices, int startVertex, bool *visited)
{

    cout << startVertex << endl;
    visited[startVertex] = true;

    for (int i = 0; i < vertices; i++)
    {
        if (i == startVertex)
        {
            continue;
        }
        if (edgeMatrix[startVertex][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print_DFS(edgeMatrix, vertices, i, visited);
        }
    }
}

int main()
{

    int vertices, edges;
    cin >> vertices >> edges;

    bool **edgeMatrix = new bool *[vertices];

    for (int i = 0; i < vertices; i++)
    {
        edgeMatrix[i] = new bool[edges];
        for (int j = 0; j < edges; j++)
        {
            edgeMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edgeMatrix[firstVertex][secondVertex] = 1;
    }

    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }

    print_DFS(edgeMatrix, vertices, 1, visited);

    for (int i = 0; i < vertices; i++)
    {
        delete[] edgeMatrix[i];
    }
    delete[] edgeMatrix;
    delete[] visited;

    return 0;
}