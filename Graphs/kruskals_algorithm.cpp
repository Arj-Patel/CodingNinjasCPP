/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
int getparent(int v , int parent[])
{
    if(v==parent[v])
        return v;
    return getparent(parent[v],parent);
}
bool sort_by_weight(Edge a , Edge b)
{
    return a.weight<b.weight;
}
int main() {

    int v,e;
    cin>>v>>e;

    Edge input[e];
    Edge output[v-1];
    int parent[v];

    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        input[i].source=x;
        input[i].dest=y;
        input[i].weight=z;
    }
    sort(input,input+e,sort_by_weight);

    int k=0;
    for(int i=0 ; i<e && k<v-1 ; i++)
    {
        int v1=input[i].source;
        int v2=input[i].dest;
        int p1=getparent(v1,parent);
        int p2=getparent(v2,parent);
        if(p1!=p2)
        {
            if(v1<v2)
            {
                output[k].source=v1;
                output[k].dest=v2;
            }
            else
            {
                output[k].source=v2;
                output[k].dest=v1;
            }
            output[k].weight=input[i].weight;
            k++;
            parent[p1]=p2;
        }
    }
    for(int i=0;i<v-1;i++)
    {
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int source, destination, weight;

    edge()
    {
        source = 0;
        destination = 0;
        weight = 0;
    }

    edge(int s, int d, int w)
    {
        source = s;
        destination = d;
        weight = w;
    }
};

bool comparator(edge const &a, edge const &b)
{
    return a.weight < b.weight;
}

int getTopParent(int *parent, int source)
{

    // int i = source;
    // while(parent[i] != i){
    //     i = parent[i];
    // }
    // parent[source] = i;

    // i = destination;
    // while(parent[i] != i){
    //     i = parent[i];
    // }
    // parent[destination] = i;

    if (parent[source] == source)
    {
        return source;
    }

    getTopParent(parent, parent[source]);

    return parent[source];
}

void kruskalAlgo(edge *input, int *parent, edge *output, int n, int e)
{

    int j = 0;
    for (int i = 0; i < e; i++)
    {
        int sParent = getTopParent(parent, input[i].source);
        int dParent = getTopParent(parent, input[i].destination);

        // int sParent = parent[input[i].source], dParent = parent[input[i].destination];

        if (sParent != dParent)
        {

            output[j].source = input[i].source;
            output[j].destination = input[i].destination;
            output[j].weight = input[i].weight;
            // cout<<output[j].source<<" "<<output[j].destination<<" "<<output[j].weight<<endl;
            // if(dParent < sParent){
            //     parent[input[i].source] = dParent;
            // }
            // else{
            //     parent[input[i].destination] = sParent;
            // }

            parent[dParent] = sParent;

            j++;
        }
        if (j == n - 1)
        {
            break;
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    edge *input = new edge[e];

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        // cout<<i<<endl;
        input[i] = edge(s, d, w);
    }

    sort(input, input + e, comparator);

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    edge *output = new edge[n - 1];

    // for(int i = 0; i < e; i++){
    //     cout<<input[i].source<<" "<<input[i].destination<<" "<<input[i].weight<<endl;
    // }
    // cout<<input[6].source<<" "<<input[6].destination<<endl;

    kruskalAlgo(input, parent, output, n, e);

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source <= output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

    delete[] input;
    delete[] output;
    delete[] parent;

    return 0;

    /*
9 12
8 2 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14

9 10
8 2 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4 9
5 4 10

9 12
8 2 1
0 1 1
2 5 1
8 6 1
2 3 1
7 8 1
0 7 1
1 2 1
3 4 1
5 4 1
1 7 1
3 5 1

    */
}
