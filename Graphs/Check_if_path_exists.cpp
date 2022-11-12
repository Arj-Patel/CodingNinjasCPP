#include <bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int sv, int ev)
{

    for (int i = 0; i < n; i++)
    {
        if (edges[sv][ev] == 1)
        {
            return true;
        }
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    q.push(sv);

    while (!q.empty())
    {

        int current = q.front();
        visited[current] = true;
        q.pop();
        if (edges[current][ev] == 1)
        {
            return true;
        }

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

    return false;
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

    int sv, ev;
    cin >> sv >> ev;

    if (hasPath(edges, n, sv, ev))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}