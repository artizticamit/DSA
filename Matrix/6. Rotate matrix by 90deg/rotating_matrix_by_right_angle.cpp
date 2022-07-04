#include<bits/stdc++.h>
 
using namespace std;

//_________________________Naive solution___________________
void rotate90_anti(int mat[m][n])
{
    int temp[m][n];
    {
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                temp[m-j-1][i] = mat[i][j];
            }
        }
    }
}
 
int main()
{
    
    return 0;
}