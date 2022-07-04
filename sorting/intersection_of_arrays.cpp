#include<iostream>
 
using namespace std;

void intersection(int a[], int b[], int n, int m)
{
    for(int i= 0; i<n; i++)
    {
        if(i>0 && a[i-1] == a[i])
        {
            continue;
        }
        for(int j = 0; j<m; j++)
        {
            // cout<<"a[i] = "<<a[i]<<"\n";
            if(a[i] == b[j])
            {
                cout<<a[i]<<" ";
                // break;
            }
        }
    }
}

void interesection2(int a[], int b[], int n, int m)
{
    int i= 0, j= 0;
    while(i<n && j<m)
    {
        if(i>0 && a[i-1]==a[i])
        {
            i++;
            continue;
        }
        if(a[i]<b[j]) i++;
        else if(b[j]<a[i]) j++;
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}
 
int main()
{
    int a[] = {3, 5,10, 10 , 10, 15, 15, 20};
    int b[] = {5 , 10, 10, 15, 30};

    // intersection(a, b, 8, 5);
    interesection2(a, b, 8,5);
    return 0;
}