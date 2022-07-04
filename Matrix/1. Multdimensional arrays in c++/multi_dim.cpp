#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
/*
    //************Declaration of multidimensional arrays*************
    // 2-Dimensional Array
    int arr[3][2] = {{10, 20}, {1, 2}, {23, 34}};
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<2; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    int arr1[1][2][3]; // 3-dim array

*/
/*

    //******************Double pointer declaration*************
    int m = 3, n = 2;
    int **arr2;
    arr2 = new int *[m];
    for(int i=0; i<m; i++)
    {
        arr2[i] = new int[n];
    }
    for(int i = 0; i<m ; i++)
    {
        for(int j = 0; j<n; j++)
        {
            arr2[i][j] = 10;
            cout<<arr2[i][j]<<" ";
        }
    }

    cout<<endl;

*/

/*
    //******************* Using Array of pointers i.e Single pointer ******************
    int m = 3, n = 2;
    int *arr3[m];
    
    for(int i=0; i<m; i++)
    {
        arr3[i] = new int[n];
    }
    for(int i = 0; i<m ; i++)
    {
        for(int j = 0; j<n; j++)
        {
            arr3[i][j] = 10;
            cout<<arr3[i][j]<<" ";
        }
    }
*/
/*
    //****************** Array of vectors **********

    int m = 3, n = 2;
    vector<int> arr4[m];
    
    for(int i=0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            arr4[i].push_back(10);
        }
    }
    for(int i = 0; i<m ; i++)
    {
        for(int j = 0; j<n; j++)
        {
            
            cout<<arr4[i][j]<<" ";
        }
    }
*/

    //******************* Vector of vectors*************
    int m = 3, n = 2;
    vector<vector<int>> arr5;
    
    for(int i=0; i<m; i++)
    {
        vector<int> v;
        for(int j = 0; j<n; j++)
        {
            v.push_back(10);
        }
        arr5.push_back(v);
    }
    for(int i = 0; i<m ; i++)
    {
        for(int j = 0; j<n; j++)
        {
            
            cout<<arr5[i][j]<<" ";
        }
    }

    return 0;
}