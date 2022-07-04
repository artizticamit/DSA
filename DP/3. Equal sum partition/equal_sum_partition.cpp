#include<bits/stdc++.h>
 
using namespace std;
#define vi vector<int>
#define ll long long int

bool subsetSum(int arr[], int sum, int n)
{
    bool dp[n+1][sum+1];

    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0; j<sum+1; j++)
        {
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }

    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<sum+1; j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

bool equalSumPart(int arr[], int n)
{
    ll sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0) return false;
    else{
        return subsetSum(arr, sum/2, n);
    }
}
 
int main()
{
    int arr[] = {1, 5, 11, 5};
    if(equalSumPart(arr, 4) == true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}