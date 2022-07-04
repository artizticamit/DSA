#include<bits/stdc++.h>
 
using namespace std;

void bTraversal(int **mat, int m, int n)
{
    if(m==1)
    {
        for(int i = 0; i<n; i++)
        {
            cout<<mat[0][i]<<" ";
        }
    }
    else if(n == 1)
    {
        for(int i = 0; i<m; i++)
        {
            cout<<mat[i][0]<<" ";
        }
    }
    else{
        for(int i = 0; i<n; i++)
            cout<<mat[0][i]<<" ";
        for(int i = 1; i<m; i++)
            cout<<mat[i][n-1]<<" ";
        for(int i = n-2; i>=0; i--)
            cout<<mat[m-2][i]<<" ";
        for(int i = m-2; i>=1; i--)
            cout<<mat[i][0]<<" ";
    }
}
 
int main()
{
    int **arr;
    int m = 4, n = 4;
    arr = new int *[m];
    for(int i = 0; i<m; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j<n; j++)
        {
            arr[i][j] = i+j;
            // cout<<arr[i][j]<<" ";
        }
    }
    bTraversal(arr, m, n);
    return 0;
}