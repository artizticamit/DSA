#include<iostream>
#include<algorithm>
#include<string>
 
using namespace std;

struct Queue{
    int size, cap;
    int *arr;
    Queue(int c)
    {
        cap =c;
        size = 0;
        arr = new int[cap];
    }

};
 
int main()
{
    
    return 0;
}