#include<bits/stdc++.h>
 
using namespace std;

void kthBit(int n, int k)
{
    if( n & (1<<(k-1)) != 0) printf("Yes\n");
    else printf("No\n");
}


int main()
{
    kthBit(5, 1);
    kthBit(8, 2);
    kthBit(0, 3);

    
    return 0;
}