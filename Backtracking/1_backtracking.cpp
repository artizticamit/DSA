// @artistic_coder

#include<iostream>
#include<string>
using namespace std;

// We are learning Backtracking from example.

// Given a string, print all those permutations which do not contain "AB" as a substring.
// I/p : str = "ABC";
// O/p : ACB, BAC, BCA, CBA

//This part is for backtracking not for naive solution
bool isSafe(string str, int l,int i, int r);

// Naive solution
void permute(string str, int l, int r)
{
    if(l==r)
    {
        cout<<str<<endl;// print(str); 
        // if(str.find("AB")==string::npcs)
        return;
    }
    for(int i = l; i<=r; i++)
    {
        // This part is for backtracking which  is added later on
        if(isSafe(str, l, i, r))
        {
            swap(str[i] , str[l]);
            permute(str, l+1, r);
            swap(str[i], str[l]);
        }
    } 
}


//Backtracking
// - What we do in backtracking is we add a condition before the recursive call 

bool isSafe(string str, int l,int i, int r)
{
    if(l!=0 && str[l-1]=='A' && str[i]=='B') return false;
    if(r==l+1 && str[i]=='A' && str[l]=='B') return false;
    return true;
}


int main()
{
    string s = "ABCD";
    permute(s, 0, 3);
    return 0;
}
