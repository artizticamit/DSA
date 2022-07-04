#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    int data;
    struct node *next;

};

struct node * createNode(int v)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;
}

struct Graph
{
    int numVertices;
    struct node ** adj;
    int * visited;

};

struct Graph * createGraph(int vertices)
{
    struct Graph * graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adj = malloc(vertices*sizeof(struct node *));
    graph->visited = malloc(vertices*sizeof(int));

    for(int i=0; i<vertices; i++)
    {
        graph->adj[i] = NULL;
        graph->visited[i] =0;
    }
    return graph;
}

void addEdge(struct Graph * graph, int src, int dest)
{

    // src to dest
    struct node * newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    // dest to src

    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void DFSRec(struct Graph * graph, int s)
{
    graph->visited[s] = 1;
    printf("Visited  %d\n", s);

    struct node * temp = graph->adj[s];
    while(temp!=NULL)
    {
        if(graph->visited[temp->data]==0)
        {
            DFSRec(graph, temp->data);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph * graph, int v)
{
    for(int i =0; i<v; i++)
    {
        if(graph->visited[i]==0)
        {
            DFSRec(graph, i);
        }
    }
}


int main()
{
    struct Graph * graph = createGraph(4); // 3 == number of vertices;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 0, 3);

    DFS(graph, 3);

    return 0;
}