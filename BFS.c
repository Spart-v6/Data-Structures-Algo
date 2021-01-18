#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define v 5

typedef struct Queue{
    int size; 
    int front;
    int rear; 
    int *arr;
}queue;

int isFull(queue *q){
    if(q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(queue *q){
    if(q->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(queue *q,int data){
    if(isFull(q))
        printf("Queue Overflow\n");
    else{
        if(q->front == -1)
            q->front = 0;
        // printf("Pushing %d element\n",data);
        q->rear ++;
        q->arr[q->rear] = data;
    }
}

int dequeue(queue *q){
    int a = -1; 
    if(isEmpty(q))
        printf("Queue Underflow!\n");
    else{
        a = q->arr[q->front];
        q->front++;
        if(q->front > q->rear)
            q->front = q->rear = -1;
    }
    return a;
}

void bfs(int arr[v][v],int src,queue *q){
    int Visited[v] = {0,0,0,0,0}; //coz 5 vertex r there in graph
    int node;
    enqueue(q,src); //queued the starting node..
    Visited[src] = 1; //coz the source will be already be visited kyuki start hi vhi se ho rha hai

    node = dequeue(q);
    // printf("Visited node is %d\n",node);
    printf("%d -> ",node);

    while(true){

        for(int i =0; i<v; i++){
            if(arr[node][i] == 1 && Visited[i] == 0){ 
            //  it checks whether there's a root which exists meanas is there any adjacent node is there or not
            //  it checks whether the node is visited or not  
                Visited[i] = 1; //if visited turn it value to 1
                enqueue(q,i); //and enqueue that node to queue
            }
        }
        if(isEmpty(q)){
            break;
        }
        else{
            node = dequeue(q);
            // printf("Visited node is %d\n",node);
            printf("%d -> ",node);
        }
    }
}

int main(){
    queue *q = (queue *) malloc(sizeof(queue)); 
    q->size = 100; 
    q->front = q->rear = -1; 
    q->arr = (int *) malloc (q->size * sizeof(int)); // array of size 100 is created

    int arr[5][5] = {   {0,1,1,1,0},
                        {1,0,0,1,1},
                        {1,0,0,1,0},
                        {1,1,1,0,1},
                        {0,1,0,1,0}};
    
    printf("\nBreadth First Traversal is \n");
    bfs(arr,0,q); //src = 0 means start from 0th node
    printf("\n\n");
    return 0;
}