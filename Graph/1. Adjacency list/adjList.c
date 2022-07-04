#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * addNode(int val)
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    head->data = val;
    head->next = NULL;
}

void addEdge(struct Node arr[], int v, int u)
{
    struct Node * first = addNode(u);
    struct Node * second = addNode(v);
    arr[u].next = second;
    arr[v].next = first;
}

int main()
{
    int V = 4;
    struct Node arr[4];
    addEdge(arr, 0, 1);
    addEdge(arr, 0, 2);

    printf("The value of adjacency list  %d and %d", arr[0].next->data, arr[1].next->data);

    return 0;
}