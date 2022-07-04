#include<bits/stdc++.h>
 
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt<b.wt;
}

int findPair(int u, vector<int> &parent)
{
    if(u==parent[u])return u;
    return findPair(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPair(u, parent);
    v = findPair(v, parent);
    if(rank[u]<rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
 
int main()
{
    int N,m;
    cin>>N>>m;

    vector<node> edges;
    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u, v, wt));
    }
    
    int src;
    cin>>src;

    int inf = INT_MAX;
    vector<int> dist(N, inf);
    dist[src]= 0;

    for(int i=0; i<=N-1; i++) // running V-1 times as V=N
    {
        for(auto it:edges) // traversing through every edges
        {
            if(dist[it.u] + it.wt< dist[it.v])   // Relaxation
            {
                dist[it.v] = dist[it.u] + it.wt;   
            }
        }
    }
    int fl = 0;
    for(auto it:edges)
    {
        if(dist[it.u] + it.wt < dist[it.v])
        {
            cout<<"Negative cycle\n";         /// checking for negative weight cycle
            fl=1;
            break;
        }
    }

    if(!fl)
    {
        for(int i=0; i<N; i++)
        {
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
    
    return 0;
}