#include<bits/stdc++.h>
 
using namespace std;


void addEdge(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for(int i = 0; i<v; i++)
    {
        for(int x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

void prims(vector<int> adj[], int V)
{
    int parent[V];
    int key[V];
    bool setMST[V];

    priority_queue<int> Q(V);

    for(int i=0; i<V; i++)
    {
        parent[i] = -1;
        key[i] = INT_MAX;
        setMST[i] = false;
        Q.push(key[i]);
    }
    key[0]=0;
    
    parent[0] = 0;
    for(int i=0; i<V; i++)
    {
        int u = Q.top();
        Q.pop();
        setMST[u] = true;

        for(auto it:adj[u])
        {
            if(setMST[it]==false && )
        }
    }

}
 
int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    printGraph(adj, v);

    
    return 0;
}