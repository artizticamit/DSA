#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
    TrieNode * child[2];
    TrieNode(){
        child[0] = child[1] = NULL;
    }
};

bool insert(TrieNode *root, vector<vector<int>> &mat, int row)
{
    TrieNode * curr = root;
    if(root==NULL) return NULL;
    bool flag = false;
    for(int i = 0; i<mat[row].size(); i++)
    {
        int index = mat[row][i];
        if(curr->child[index]==NULL)
        {
            curr->child[index] = new TrieNode();
            flag = true;
        }
        curr = curr->child[index];
    }
    return flag;
}

int countDist(vector<vector<int>> &mat)
{
    TrieNode * root = new  TrieNode();
    int res= 0;
    for(int row = 0; row<mat.size(); row++)
    {
        if(insert(root, mat, row)==true)
        {
            res++;
        }
    }
    return res;
}

int main()
{

    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++){
        vector<int> t;
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            t.push_back(x);
        }
        mat.push_back(t);
    }
    cout<<countDist(mat)<<"\n";

    return 0;
}