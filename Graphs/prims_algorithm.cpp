#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *weight, bool *visited, int n)
{

    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void primsAlgorithm(int **edges, int n, int *parent, int *weight, bool *visited)
{

    for (int i = 0; i < n; i++)
    {

        int minVertex = findMinVertex(weight, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
}

/*
void primsAlgorithm(int **edges, int n, int *parent, int *weight, bool *visited) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (edges[i][j] != 0 && !visited[i]) {
        if (edges[i][j] < weight[j]) {
            weight[j] = edges[i][j];
            parent[j] = i;
        }
      }
    }
    visited[i] = true;
  }
}
*/

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

    int s, d, w;

    for (int i = 0; i < e; i++)
    {
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int *parent = new int[n];
    parent[0] = -1;

    int *weight = new int[n];

    weight[0] = 0;
    for (int i = 1; i < n; i++)
    {
        weight[i] = INT_MAX;
    }

    primsAlgorithm(edges, n, parent, weight, visited);

    //   for (int i = 1; i < n; i++) {
    //     if (i < parent[i]) {
    //       cout << i << " " << parent[i] << " " << weight[i] << endl;
    //     } else {
    //       cout << parent[i] << " " << i << " " << weight[i] << endl;
    //     }
    //   }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] parent;
    delete[] weight;
    delete[] visited;

    return 0;

    /*

    5 6
    0 1 4
    1 2 2
    1 3 6
    2 3 3
    2 4 9
    3 4 5

  5 4
  0 1 4
  1 2 2
  2 3 3
  3 4 5

    */
}