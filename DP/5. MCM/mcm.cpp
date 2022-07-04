#include<bits/stdc++.h>
 
using namespace std;

// _________________________________RECURSIVE_________________________________
// int solve(int arr[], int i, int j)
// {
//     if(i>=j) return 0;
//     int minn = INT_MAX;
//     for(int k = i; k<j; k++)
//     {
//         int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];

//         minn = min(minn, temp);
//     }
//     return minn;
// }


// ____________________________MEMOIZATION______________________________    
int dp[1001][1001];
int solve(int arr[], int i, int j)
{
    if(i>=j) return dp[i][j] = 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int minn = INT_MIN;
    for(int k = i; k<j; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];

        minn = max(minn, temp);
    }
    return dp[i][j] =  minn;
}
 
int main()
{
    int arr[] = {1, 100, 5, 50, 1};
    memset(dp, -1, sizeof(dp));
    cout<<solve(arr, 1, 5-1)<<endl;
    return 0;
}