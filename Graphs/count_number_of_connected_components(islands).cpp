#include <bits/stdc++.h>
using namespace std;

int markConnected(int **edges, int n, int sv, bool *visited)
{

    int count = 0;
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

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
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return count;
}

int countConnected(int **edges, int n, bool *visited)
{

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            markConnected(edges, n, i, visited);
            visited[i] = true;
            count++;
        }
    }

    return count;
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

    cout << countConnected(edges, n, visited) << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;

    return 0;
}