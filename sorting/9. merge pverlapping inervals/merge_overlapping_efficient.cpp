#include<bits/stdc++.h>
 
using namespace std;

struct Interval{
    int st, end;
};

bool mycomp(Interval a, Interval b)
{
    return (a.st < b.st);
}

int max(int a, int b)
{
    return a>b?a:b;
}

int min(int a, int b)
{
    return a<b?a:b;
}

// This is an efficient solution for solving the problem merge overlapping Inervals

void merge_intervals(Interval arr[], int n)
{
    sort(arr, arr+n, mycomp);
    int res = 0;
    for(int i = 1; i<n; i++)
    {
        if(arr[res].end >= arr[i].st)
        {
            arr[res].st = min(arr[res].st, arr[i].st);
            arr[res].end = max(arr[res].end, arr[i].end);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }

    for(int i = 0; i<=res; i++)
    {
        cout<<arr[i].st<<" "<<arr[i].end<<endl;
    }
}
 
int main()
{
    int n = 4;
    // Interval arr[4];
    // arr[0].st = 2;
    // arr[0].end = 7;
    
    // arr[1].st = 3;
    // arr[1].end = 15;

    // arr[2].st = 5;
    // arr[2].end = 10;

    // arr[3].st = 18;
    // arr[3].end = 30;

    Interval arr[] = {{2, 7}, {3, 15}, {5, 10}, {18, 30}};
    merge_intervals(arr, n);

    return 0;
}