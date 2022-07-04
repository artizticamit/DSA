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

bool DFSRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    // cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
        {
            if(DFSRec(adj, u, visited, s)==true)
            {
                return true;
            }
        }
        else if(u!=parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for(int i = 0; i<v; i++) visited[i] = false;

    for(int i = 0; i<v; i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, -1)==true)
                return true;
        }
    }
    return false;
}
 
int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 0, 5);
    addEdge(adj, 2, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);

    if(DFS(adj, v))
    {
        cout<<"yes"<<"\n";
    }else cout<<"No"<<"\n";


    return 0;
}