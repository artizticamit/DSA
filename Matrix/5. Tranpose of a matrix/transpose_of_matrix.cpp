#include<bits/stdc++.h>
 
using namespace std;

const int n = 4;
const int m = 4;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// ___________________________________________Naive Solution_________________________________
void transpose1(int mat[n][n])
{
    int temp[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n ; j++)
        {
            temp[i][j] = mat[j][i];
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n ; j++)
        {
            mat[i][j] = temp[i][j];
        }
    }
}

// ___________________________________________Efficient Solution____________________________________
// --> In-place
// --> One loop

void transpose2(int mat[n][m])
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}





void printMatrix(int mat[n][m]) //___________ For printing matrix____________
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
int main()
{
    int mat[4][4]={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15 ,16}};
    // int **arr;
    // int m = 3, n = 2;
    // arr = new int *[m];
    // for(int i = 0; i<m; i++)
    // {
    //     arr[i] = new int[n];
        
    // }
    printMatrix(mat);
    transpose2(mat);
    cout<<"\n\n";
    printMatrix(mat);

    return 0;
}