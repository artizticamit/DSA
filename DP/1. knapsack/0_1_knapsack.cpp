#include<bits/stdc++.h>

#define ll long long int
#define vi vector<int>

using namespace std;

//_______________________________ This was recursive solution for the 0/1 knapsack problem_______________________________

// int knapSack(vi wt, vi val, int cap, int n)
// {
//     if(n==0||cap==0) return 0;
//     if(wt[n-1]<=cap)
//     {
//         return max(val[n-1]+knapSack(wt, val, cap-wt[n-1], n-1), knapSack(wt, val, cap, n-1));
//     }
//     else return knapSack(wt, val, cap, n-1);
// }


//_______________________________________DP solution using recursion + dp = memoization____________________________________

// CONSTRAINTS :
// n<=100
// W(capacity)<=1000


// int dp[102][1002];
// memset(dp, 0, sizeof(dp));  // IN C++ the global arrays are already initialized with 0 so e don't have to use memset it will give an error

// int knapSack(vi wt, vi val, int cap, int n)
// {
//     if(n==0||cap==0) return 0;

//     if(dp[n][cap]!=0)
//     {
//         return dp[n][cap];
//     }

//     if(wt[n-1]<=cap)
//     {
//         return dp[n][cap] = max(val[n-1]+knapSack(wt, val, cap-wt[n-1], n-1), knapSack(wt, val, cap, n-1));
//     }
//     else return dp[n][cap] = knapSack(wt, val, cap, n-1);
// }


// ________________________________ Top down method (tabular  method)___________________________

int knapSack(vi wt, vi val, int W, int n)
{
    int dp[n+1][W+1];
    for(int i = 0; i<n+1; i++) dp[i][0] = 0;
    for(int i = 0; i<W+1; i++) dp[0][i] = 0;

    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<W+1; j++)
        {
            if(wt[i-1]<= j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0; j<W+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    return dp[n][W];

}

void solve()
{
    int n, cap;
    cin>>n;
    vi w(n), val(n);
    for(int i = 0; i<n; i++) cin>>w[i];
    for(int i = 0; i<n; i++) cin>>val[i];
    cin>>cap;
    int res = knapSack(w, val, cap, n);
    cout<<res<<endl;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}