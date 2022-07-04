// @artistic_coder

#include<bits/stdc++.h>
using namespace std;


// Rat in a maze problem
/*
 In this problem we have been given a maze of NxN size where 0 represents blocked cell and 1 represents hollow cell/unblocked cell(path for rat). The mouse is at the top left corner of the maze and the at the right bottom corner there is cheese. The rat wants to reach to the cheese. The mouse can move only one step at a time and can move only in right direction or bottom direction.
 Rate has to collect the cheese.
*/


/* I/p : maze[][] = {{1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {0, 1, 0, 0},
                     {1, 1, 1, 1}}
    
    O/p : Yes
          1 0 0 0
          1 1 0 0
          0 1 0 0
          0 1 1 1
*/

/* I/p : maze[][] = {{1, 0, 0},
                     {0, 1, 0},
                     {1, 1, 1}}
    
    O/p : No
          
*/


// My solutio
// int N;

// void rat(vector<vector<int>>& maze, int i, int j)
// {
//     if(i==N && j == N)
//     {
//         cout<<"YES\n";
//         return;
//     }
//     if(maze[i+1][j] ==0 && maze[i][j+1] == 0)
//     {
//         cout<<"NO\n";
//         return;
//     }
//     else if(maze[i+1][j]==1)
//     {
//         rat(maze, i+1, j);
//     }
//     else if(maze[i][j+1]==1)
//     {
//         rat(maze, i, j+1);
//     }
// }

// void solution(vector<vector<int>>& maze)
// {
//     N = maze.size();
//     rat(maze, 0,0);
// }

// int main()
// {
//     vector<vector<int>> maze;
//     int m[4][4] = {{1, 0, 0, 0},
//                      {1, 1, 0, 1},
//                      {0, 1, 0, 0},
//                      {1, 1, 1, 1}};
//     for(int i = 0; i<4; i++)
//     {
//         vector<int> temp(4);
//         for(int j = 0; j<4; j++)
//         {
//             temp[j] = m[i][j];
//         }
//         maze.push_back(temp);
//     }

//     solution(maze);
//     return 0;
// }


int N=4;

// bool maze[N][N], sol[N][N];
// vector<vector<int>> maze, sol;
bool solveMazeRec(vector<vector<int>>& sol,vector<vector<int>>& maze,int i, int j);

void printMatrix(vector<vector<int>>& sol)
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

bool isSafe(vector<vector<int>>& maze,int i, int j)
{
    return (i<N && j<N && maze[i][j]==1); 
}

bool solveMaze(vector<vector<int>>& sol, vector<vector<int>>& maze)
{
    if(solveMazeRec(sol,maze,0, 0)==false) return false;
    else{
        printMatrix(sol);
        return true;
    }
}

bool solveMazeRec(vector<vector<int>>& sol,vector<vector<int>>& maze,int i, int j)
{
    if(i==N-1 && j == N-1)
    {
        sol[i][j] = 1;
        return true;
    }
    if(isSafe(maze,i, j)==true)
    {
        sol[i][j] = 1;
        if(solveMazeRec(sol, maze,i+1, j)==true) return true;
        else if(solveMazeRec(sol, maze, i, j+1)==true) return true;
        sol[i][j] = 0;
    }
    return false;
}

int main()
{
    vector<vector<int>> maze, sol;
    int m[4][4] = {{1, 0, 0, 0},
                     {1, 0, 0, 1},
                     {1, 1, 0, 0},
                     {1, 1, 1, 1}};
    for(int i = 0; i<4; i++)
    {
        vector<int> temp(4), temp1(4);
        for(int j = 0; j<4; j++)
        {
            temp[j] = m[i][j];
            temp1[j] = 0;
        }
        maze.push_back(temp);
        sol.push_back(temp1);
    }

    if(solveMaze(sol, maze)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}