#include<bits/stdc++.h>
 
using namespace std;

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
 
int main()
{
    int arr[] = {2, 3};
    int sum = 5;
    if(subsetSum(arr, sum, 2) == true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}