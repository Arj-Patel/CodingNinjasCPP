#include <bits/stdc++.h>
using namespace std;

vector<int>* getDFSPath(int** edges, int n,int sv, int ev, bool* visited){

    if(sv == ev){
        vector<int>* v;
        visited[sv] = true;
        v->push_back(ev);
        return v;
    }

    for(int i = 0; i < n; i++){
        if(i == sv){
            continue;
        }
        visited[sv] = true;
        if(edges[sv][i] == 1 && !visited[i]){
            visited[i] = true;
            vector<int>* ans = getDFSPath(edges, n, i, ev, visited);
            if(ans != NULL){
                ans->push_back(sv);
                return ans;
            }
        }
    }

    return NULL;

}

int main() {
    
    int n, e;
    cin>>n>>e;

    int** edges = new int*[n];

    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
          edges[i][j] = 0;
        }
    }

    int f, s;

    for(int i = 0; i < e; i++){
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int sv, ev;
    cin>>sv>>ev;

    bool* visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    vector<int>* v = getDFSPath(edges, n, sv, ev, visited);

    if(v == NULL){
        return 0;
    }

    for(int i =0; i < v->size(); i++){
        cout<<v->at(i)<<" ";
    }
    cout<<endl;

    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}