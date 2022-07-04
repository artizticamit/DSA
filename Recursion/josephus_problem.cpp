#include<iostream>
#include<algorithm>
#include<string>
 
using namespace std;

int josephus( int n, int k)
{
    if(n==1)
    {
        return 0;
    }

    return (josephus(n-1, k)+k)%n;
}
 
int main()
{
    // int n, k;
    // cin>>n>>k;
    // int a[n];
    // for(int i = 0; i<n; i++)
    // {
    //     cin>>a[i];
    // }
    int ans = josephus(5,3);
    cout<<ans;
    return 0;
}