#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue
{
    int size;
    int f, r;
    int * arr;
};

int isFull(struct queue * q)
{
    if((q->r+1)%q->size == q->f)
    {
        // printf("The queue is full\n");
        return 1;
    }
    return 0;
    
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("The queue is full\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }

}
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

int main()
{
    
    return 0;
}