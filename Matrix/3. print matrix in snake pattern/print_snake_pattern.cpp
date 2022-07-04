#include<bits/stdc++.h>
 
using namespace std;

void print_snake(int **arr, int m, int n)
{
    for(int i = 0; i<m; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0; j<n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j = n-1; j>=0; j--)
            {
                cout<<arr[i][j]<<" ";
            }
        }
    }
}
 
int main()
{
    int **arr;
    int m = 3, n = 2;
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
    print_snake(arr, m, n);
    return 0;
}