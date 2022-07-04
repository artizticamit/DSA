#include<bits/stdc++.h>
 
using namespace std;
#define rep(n) for(int i = 0; i<n; i++)

//_________________________________RECURSIVE_________________________________
// int lcs(string x, string y, int n, int m)
// {
//     if(n==0 || m==0) return 0;
//     if(x[n-1]==y[m-1]) return (1+lcs(x, y, n-1, m-1));
//     else{
//         return max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
//     }
// }

// ______________________________Memoization________________________________
// int static dp[1001][1001];

// int lcs(string x, string y, int n, int m)
// {
//     if(n==0 || m==0) return dp[n][m] = 0;
//     if(dp[n][m]!=-1)
//     {
//         return dp[n][m];
//     }
//     if(x[n-1]==y[m-1]) return dp[n][m] = (1+lcs(x, y, n-1, m-1));
//     else{
//         return dp[n][m] = max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
//     }
// }
 

// ___________________________Top Down approach_____________________________
int lcs(string x, string y, int n, int m)
{
    int dp[x.length()+1][y.length()+1];
    rep(x.length()+1) dp[i][0] = 0;
    rep(y.length()+1) dp[0][i] = 0;

    for(int i = 1; i<x.length()+1; i++)
    {
        for(int j = 1; j<y.length()+1; j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = (1+dp[i-1][j-1]);
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[x.length()][y.length()];
}


int main()
{
    string x = "ABCDEFHIJKG";
    string y = "ABDEFG";
    // memset(dp, -1, sizeof(dp));
    cout<<lcs(x, y, x.length(), y.length())<<endl;
    return 0;
}