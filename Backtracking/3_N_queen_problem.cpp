//@artistic_coder


// N queen problem
/*
In this we are given N value which depicts NxN chess board, and we have to place N queens on this board such that no two queens attack each other.
*/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vector<int>>



//Naive solution would be to generate all possible permutations/configurations that is (n^2)Cn = (n^2)!/ (n^2-n)!n! possibiblties.
// Bcoz we have NxN chess board and we have N queens to to arrange them


void printMatrix(vector<vector<bool>>& sol)
{
    int n = sol.size();
    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafe(vector<vector<bool>> &board, int row, int col)
{
    for(int i = 0; i<col; i++)
    {   
        if(board[row][col]) return false;
    }   

    for(int i=row, j = col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j]) return false;
    }
    for(int i=row, j = col; i<board.size() && j>=0; i++, j--)
    {
        if(board[i][j]) return false;
    }

    return true;

}



bool solveRec(vector<vector<bool>> &board,int col)
{
    if(col==board.size()) return true;

    for(int i =0; i<board.size(); i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = true;
            if(solveRec(board, col+1))
            {
                return true;
            }
            board[i][col] = false;
        }
    }
    return false;
}

bool solve(vector<vector<bool>> &board)
{
    if(solveRec(board, 0)==false)
    {
        return false;
    }
    printMatrix(board);
    return true;
}


int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<bool>> board;
    for(int i = 0; i<N; i++)
    {
        vector<bool> temp;
        for(int j = 0; j<N; j++)
        {
            temp[j] = false;
        }
        board.push_back(temp);
    }
    solve(board);

    return 0;
}
