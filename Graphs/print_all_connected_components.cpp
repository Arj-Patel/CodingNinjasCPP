#include <bits/stdc++.h>
using namespace std;

void print(int **edgeMatrix, int v, int startVertex, bool *visited)
{

    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    vector<int> vec;

    while (!q.empty())
    {

        int current = q.front();
        vec.push_back(current);
        q.pop();
        for (int i = 0; i < v; i++)
        {
            if (i == current)
            {
                continue;
            }
            if (edgeMatrix[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void print(int **edgeMatrix, int v)
{

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            print(edgeMatrix, v, i, visited);
            cout << endl;
        }
    }
}

int main()
{

    int v, e;
    cin >> v >> e;

    if (v == 0)
    {
        return 0;
    }

    int **edgeMatrix = new int *[v];

    for (int i = 0; i < v; i++)
    {
        edgeMatrix[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edgeMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int first, second;
        cin >> first >> second;
        edgeMatrix[first][second] = 1;
        edgeMatrix[second][first] = 1;
    }

    print(edgeMatrix, v);

    for (int i = 0; i < v; i++)
    {
        delete[] edgeMatrix[i];
    }
    delete[] edgeMatrix;

    return 0;
}