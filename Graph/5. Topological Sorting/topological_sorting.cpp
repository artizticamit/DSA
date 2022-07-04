#include<bits/stdc++.h>
 
using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
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

bool DFSRec(vector<int> adj[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    // cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
        {
            if(DFSRec(adj, u, visited, recSt)==true)
            {
                return true;
            }
        }
        else if(recSt[u] == true)
        {
            return true;
        }
    }
    recSt[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    bool recSt[v];
    for(int i = 0; i<v; i++)
    {
        visited[i] = false;
        recSt[i] = false;
    }

    for(int i = 0; i<v; i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, recSt)==true)
                return true;
        }
    }
    return false;
}

void topological_sorting(vector<int> adj[], int v, bool visited[])
{
    stack<int> st;
    for(int i = 0; i<v; i++)
    {
        visited[i] =false;
    }
    for(int u: adj[])
}
 
int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    // addEdge(adj, 0, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    printGraph(adj, v);




    return 0;
}