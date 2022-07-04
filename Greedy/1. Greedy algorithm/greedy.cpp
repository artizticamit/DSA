#include<bits/stdc++.h>
 
using namespace std;

// Consider the example : where we have some coins and a given amount and we have to choose the minimum number of coins to achieve that given amount

int minCoins(int coins[], int n, int amount)
{
    sort(coins, coins+n, greater<int>());

    int res = 0;

    for(int i =0; i<n; i++)
    {
        if(coins[i]<= amount)
        {
            int c = floor(amount/coins[i]);
            res += c;
            amount = amount - c*coins[i];   /// {1} must present in the coins list bcoz if the least number ris larger than amount then we can't proceed further i.e. some of the amount will be left though the loop will be completed.
        }
        if(amount == 0)
        {
            break;
        }
    }
    return res;
}

void printArray(int arr[], int n)
{
    for(int i= 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
int main()
{
    int coins[] = {5, 10 , 2, 1};
    // printArray(coins, 4); 
    // minCoins(coins, 4, 100);
    // printArray(coins,4);
    cout<<minCoins(coins, 4, 57)<<"\n";
    return 0;
}