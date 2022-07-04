#include<bits/stdc++.h>
 
using namespace std;
int parent[10];
int size[10];

void make_set(int a)
{
    parent[a] = a;
    size[a]=1;
}

int find(int x)
{
    if(x!=parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);

    if(root_a==root_b)return;
    if(size[a]>size[b])
    {
        parent[b]=a;
    }else if(size[b]>size[a])
    {
        parent[a]=b;
    }
    else
    {
        parent[b]=a;
        size[a] +=1;
    }
    
}
 
int main()
{
    
    for(int i=0;i<10; i++)
    {
        make_set(i+1);
    }
    merge(1,2);
    merge(1,3);
    merge(2, 4);
    merge(2, 5);
    merge(2, 6);
    merge(2, 7);
    merge(2, 8);
    merge(2, 9);
    merge(2, 0);

    for(int i=0; i<10; i++)
    {
        cout<<i<<" "<<parent[i]<<endl;
    }
    cout<<find(9)<<endl;
    cout<<find(8)<<endl;
    cout<<find(7)<<endl;

    for(int i=0; i<10; i++)
    {
        cout<<i<<" "<<parent[i]<<endl;
    }
    
    return 0;
}