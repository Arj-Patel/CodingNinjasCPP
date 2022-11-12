#include <bits/stdc++.h>
using namespace std;

vector<int> getDFSPath(int **edges, int n, int sv, int ev, bool *visited)
{

    if (sv == ev)
    {
        vector<int> v;
        visited[sv] = true;
        v.push_back(ev);
        return v;
    }

    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        // cout<<sv<<" "<<i<<endl;
        if (edges[sv][i] == 1 && !visited[i])
        {
            visited[i] = true;
            vector<int> ans = getDFSPath(edges, n, i, ev, visited);
            if (ans.size() != 0)
            {
                ans.push_back(sv);
                return ans;
            }
        }
    }

    vector<int> v;

    return v;
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

    vector<int> v = getDFSPath(edges, n, sv, ev, visited);

    if (v.size() == 0)
    {
        return 0;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
    return 0;
}

/*
#include <iostream>
#include<vector>
using namespace std;

vector<int> hasPath(int** edges,int a,int b,int n,bool* visited){
    visited[a]=true;

    if(a==b){
        vector<int> ans;
        ans.push_back(b);
        return ans;
    }
    for(int i=0;i < n;i++){
        if(i==a || visited[i]){
            continue;
        }
        else if(!visited[i] & edges[a][i]==1){
            vector<int> small= hasPath(edges,i,b,n,visited);
            if(small.size()!=0){
                small.push_back(a);
                return small;
            }
            else continue;
        }
    }
    vector<int> ans;
    return ans;
}


int main() {
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        visited[i] = false;
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int a,b;
    cin>>a>>b;
    vector<int> path=hasPath(edges,a,b,n,visited);
    for(int i = 0; i < path.size(); i++){
        cout<<path[i]<<" ";
    }
    return 0;
}
*/