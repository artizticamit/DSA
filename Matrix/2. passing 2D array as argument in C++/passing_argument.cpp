#include<bits/stdc++.h>
 
using namespace std;

void print1(int mat[3][2])
{
    for(int i =0 ; i<3; i++)
    {
        for(int j= 0; j<2; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print2(int mat[][2], int m)
{
    for(int i =0 ; i<m; i++)
    {
        for(int j= 0; j<2; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

// There is no direct syntax in C++ to define a 2d array generally as argument but we can use `double` pointer 

// We can use another way
const int R = 3;
const int C = 2;

void print3(int mat[R][C])
{
    for(int i =0 ; i<R; i++)
    {
        for(int j= 0; j<C; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
int main()
{
    int mat[3][2] = {{10, 20}, {30, 40}, {50, 60}};
    // print1(mat);
    // print2(mat, 3);
    print3(mat);
    return 0;
}