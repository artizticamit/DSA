#include<bits/stdc++.h>
 
using namespace std;

class Interval{
    public:
        int start;
        int end;
};

int max(int a, int b)
{
    return a>b?a:b;
}

int min(int a, int b)
{
    return a<b?a:b;
}
bool is_merge(Interval a, Interval b)
{
    if( a.start - b.end <= 0)
    {
        return true;
    }
    return false;
}

// It is Naive solution 

int merge_intervals(Interval E[], int n)
{
    int i1 = 0, i2 = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if( is_merge(E[i], E[j]) && i!=j)
            {
                int start = min(E[i].start, E[j].start);
                int end = max(E[i].end, E[j].end);

                E[i].start = start;
                E[i].end = end;

                // For removing the other interval associated with j index we need another loop
                n = n-1;
                for(int k = j ; k<n; k++)
                {
                    E[k] = E[k+1];
                }
            }
        }
    }
    return n;
}



 
int main()
{
    int n = 3;
    Interval arr[3];
    arr[0].start = 1;
    arr[0].end = 3;

    arr[1].start = 5;
    arr[1].end= 10;

    arr[2].start = 2;
    arr[2].end = 7;


    // for(int i = 0; i<3; i++)
    // {
    //     cout<<"[ "<<arr[i].start<<": "<<arr[i].end<<"]\n";
    // }
    n = merge_intervals(arr, n);
    
    for(int i = 0; i<n; i++)
    {
        cout<<"[ "<<arr[i].start<<": "<<arr[i].end<<"]\n";
    }

    return 0;
}