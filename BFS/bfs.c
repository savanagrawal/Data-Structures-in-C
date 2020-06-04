#include <stdio.h>
#include <stdlib.h>

struct graph{
int V;
int E;
int *visited;
int **Adj;
};

struct graph *adjMatrixOfGraph()
{
    int u,v,i;
    struct graph *g=(struct graph*)malloc(sizeof(struct graph));
    if(g==NULL){
        printf("Memory Error");
        return;
    }
    printf("Enter number of node and number of edges");
    scanf("%d %d",&g->V,&g->E);
    g->visited=malloc((g->V)*sizeof(int));
    for(i=0;i<g->V;i++)
        g->visited[i]=0;
    g->Adj= (int**)malloc(g->V * sizeof(int *));
    for(int i=0;i<g->V;i++)
        g->Adj[i]=(int*)malloc(g->V * sizeof(int));
    if(!g->Adj){
        printf("Adj Memory Error");
        return;
    }printf(g->Adj[3][0]);
    for(u=0;u<g->V;u++){
        for(v=0;v<g->V;v++){
            g->Adj[u][v]=0;
        }printf("\n");
    }
    printf("Enter node numbers in pair that connects an edge");
    for(i=0;i<g->E;i++){
        scanf("%d %d",&u,&v);
        g->Adj[u][v]=1;
        //Since it's undirectional graph so 1 will enter at reverse also;
        g->Adj[v][u]=1;
    }
    return(g);
};

struct Queue
{
    int front, rear;
    int capacity;
    int *array;
};

struct Queue *createQueue(int cap)
{
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q)
        return(NULL);
    Q->capacity = cap;
    Q->front = Q->rear = -1;
    Q->array = malloc(sizeof(cap * sizeof(int)));
    if(!Q->array)
        return(NULL);
    return Q;
};

int isEmpty(struct Queue *Q)
{
    if(Q->front == -1)
        return(1);
    else
        return(0);
}

int isFull(struct Queue *Q)
{
    if((Q->rear + 1) % Q->capacity == Q->front)
        return 1;
    else
        return 0;
}

int QueueSize(struct Queue *Q)
{
    return((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
}

void enQueue(struct Queue *Q, int data)
{
    if(isFull(Q))
        printf("Queue is Full");
    else{
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
            Q->front = Q->rear;
    }
}

int deQueue(struct Queue *Q)
{
    int data;
    if(isEmpty(Q)){
        return(-1);
    }
    else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear){
            Q->front=Q->rear=-1;
        }
        else
            Q->front = (Q->front+1)%Q->capacity;
    }
    return(data);
}

void deleteQueue(struct Queue *Q)
{
    if(Q)
    {
        if(Q->array){
            free(Q->array);
        }
        free(Q);
    }
}

void bfs(struct graph *graph,int start)
{
    struct Queue *queue=createQueue(graph->V);
    for(int i=0;i<graph->V;i++)
        graph->visited[i]=1;
    enQueue(queue,start);
    graph->visited[start]=2;
    printf("Bread First Search: ");
    while(!isEmpty(queue)){
        int a=deQueue(queue);
        printf("%d ",a);
        graph->visited[a]=3;
        for(int i=0;i<graph->V;i++){
            if((graph->Adj[a][i]==1) && (graph->visited[i]==1)){
                enQueue(queue,i);
                graph->visited[i]=2;
            }
        }
    }
}

int main()
{
    struct graph *g;
    g=adjMatrixOfGraph();
    bfs(g,0);
}
