#include<bits/stdc++.h>
 
using namespace std;

void sort(int arr[], int n)
{
    int temp[n], flag = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == 0) 
        {
            temp[flag] = arr[i];
            flag++;
        }
    }
    for(int j= 0; j<n; j++)
    {
        if(arr[j] == 1)
        {
            temp[flag] = arr[j];
            flag++;
        }

    }
    for(int k = 0; k<n; k++)
    {
        if(arr[k] ==2)
        {
            temp[flag] =arr[k];
            flag++;
        }
    }

    for(int m =0; m<n; m++)
    {
        arr[m]= temp[m];
    }
    
}

void printArray(int arr[], int n)
{
    for (int i = 0; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
 
int main()
{
    int arr[] = {1, 2, 0, 2, 1, 2, 0};
    int n = 7;
    sort(arr, n);
    printArray(arr, n);
    return 0;
}