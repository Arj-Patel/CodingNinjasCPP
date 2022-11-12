#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> getPathBFS(int **edges, int n, int sv, int ev, bool *visited)
{

    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    unordered_map<int, int> m;

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
                m[i] = current;
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return m;
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    unordered_map<int, int> m = getPathBFS(edges, n, sv, ev, visited);

    // cout<<m.size()<<endl;

    if (m.size() == 0)
    {
        return 0;
    }

    if (m.find(ev) == m.end())
    {
        return 0;
    }

    int current;
    current = ev;
    cout << current << " ";
    while (current != sv)
    {
        // if(m.find(current) != m.end()){
        current = m.find(current)->second;
        cout << current << " ";
        // }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}