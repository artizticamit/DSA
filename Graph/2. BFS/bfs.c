#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);

int isEmpty(struct queue* q);
void printQueue(struct queue* q);

int N = 4; // number of vertices

void BFS(int adj[][N], int s, int visited[])
{
    visited[s] = 1; // Vertex is now visited;
    struct queue * q = createQueue();
    enqueue(q, s);

    while(!isEmpty(q))
    {
        // printQueue(q);
        int u = dequeue(q);
        printf("\nVisited %d\n", u);
        for(int i = 0; i<N; i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                enqueue(q, i);
            }
        }
    }

}

void BFSdis(int adj[][N], int N)
{
    int visited[N+1];
    for(int i = 0; i<N; i++)
    {
        visited[i] = 0; // 0 == false
    }
    for(int i = 0; i<N; i++)
    {
        if(visited[i] == 0)
        {
            BFS(adj, i, visited);
        }
    }
}

int main()
{
    
    int adj[4][4] = {{0, 0, 1, 0},
                     {1, 0, 0, 1},
                     {0, 0, 0, 0},
                     {1, 0, 0, 0}};
    BFSdis(adj, N);

    
    return 0;
}



// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}
