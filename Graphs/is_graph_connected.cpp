#include <bits/stdc++.h>
using namespace std;

void isConnected(int **edges, int n, bool *visited)
{

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {

        int current = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == current)
            {
                continue;
            }
            if (edges[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    isConnected(edges, n, visited);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "false" << endl;

            for (int i = 0; i < n; i++)
            {
                delete[] edges[i];
            }
            delete[] edges;
            delete[] visited;

            return 0;
        }
    }

    cout << "true" << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;

    return 0;
}