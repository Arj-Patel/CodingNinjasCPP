#include <bits/stdc++.h>
using namespace std;

int threeCycle(int **edges, int n)
{

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (edges[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j == k)
                    {
                        continue;
                    }
                    if (edges[j][k] == 1)
                    {
                        if (edges[i][k] == 1)
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count / 6;
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

    int ans = threeCycle(edges, n);

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}