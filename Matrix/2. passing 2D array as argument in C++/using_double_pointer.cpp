#include<bits/stdc++.h>
 
using namespace std;

void print(int **arr, int m, int n)
{
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

// using array of vectors

void print2(vector<int> arr[], int m)
{
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
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
            arr[i][j] = i;
            // cout<<arr[i][j]<<" ";
        }
    }

    // print(arr, m, n);

    vector<int> arr2[m];
    for(int i = 0; i<m; i++)
    {
        for(int j= 0; j<n; j++)
        {
            arr2[i].push_back(i);
        }
    }

    print2(arr2, m);

    return 0;
}