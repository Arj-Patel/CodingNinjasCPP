/*
#include <bits/stdc++.h>
using namespace std;

void dijkstrasAlgorithm(int** edges, int n, bool* visited, int* cost){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(edges[i][j] != 0 && (cost[i] + edges[i][j] < cost[j]) &&
!visited[i]){
                // cout<<i<<" "<<j<<endl;
                cost[j] = edges[i][j] + cost[i];
            }
        }
        visited[i] = true;
    }

}

int main() {

    int n, e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    int f, s, w;
    for(int i = 0; i < e; i++){

        cin>>f>>s>>w;
        edges[f][s] = w;
        // edges[s][f] = w;

    }

    bool* visited = new bool[n];
    int* cost = new int[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
        cost[i] = INT_MAX;
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cost[0] = 0;

    dijkstrasAlgorithm(edges, n, visited, cost);

    for(int i = 0; i < n; i++){
        cout<<i<<" "<<cost[i]<<endl;
    }

    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] visited;
    delete[] cost;

}
*/

#include <bits/stdc++.h>
using namespace std;

int MinVertex(int *cost, bool *visited, int v)
{
    int min = INT_MAX;
    int vertex = -1;
    for (int i = 0; i < v; i++)
        if (!visited[i] && cost[i] < min)
        {
            min = cost[i], vertex = i;
        }

    return vertex;
}
void Dijkstra(int **graph, int v)
{
    bool *visited = new bool[v];
    int *cost = new int[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        cost[i] = INT_MAX;
    }
    cost[0] = 0; // satrting from 0;

    for (int i = 0; i < v - 1; i++)
    {
        int minvertex = MinVertex(cost, visited, v);
        visited[minvertex] = true;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && graph[minvertex][j] &&
                cost[j] > (graph[minvertex][j] + cost[minvertex]))
                cost[j] = graph[minvertex][j] + cost[minvertex];
        }
    }
    for (int i = 0; i < v; i++)
        cout << i << " " << cost[i] << endl;

    delete[] visited;
    delete[] cost;
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    // input a graph
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s][e] = w;
        graph[e][s] = w;
    }

    Dijkstra(graph, V);
    return 0;
}