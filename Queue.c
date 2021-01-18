#include<stdio.h>
#include<stdlib.h>

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
    if(q->rear == q->front)
        return 1;
    else
        return 0;
}

void enqueue(queue *q,int data){
    if(isFull(q))
        printf("Queue Overflow\n");
    else{
        printf("Pushing %d element\n",data);
        q->rear ++;
        q->arr[q->rear] = data;
    }
}

int dequeue(queue *q){
    int a = -1; //shows -1 ... if smth bad happens
    if(isEmpty(q))
        printf("Queue Underflow!\n");
    else{
        a = q->arr[q->front];
        q->front++;
    }
    return a;
}

int peek(queue *q, int i){
    int pos = q->rear-i;
    if(pos<0){
        printf("Invalid position");
        return -1;
    }
    else{
        return q->arr[pos];
    }
} 

int main()
{
    queue *q = (queue *) malloc(sizeof(queue)); //u gotta pass address (&) if u don't declare it as pointer!
    q->size = 5; 
    q->front = q->rear = -1; //initially it's empty
    q->arr = (int *) malloc (q->size * sizeof(int));

    // printf("%d",q->size);
    enqueue(q,20);
    enqueue(q,46);
    enqueue(q,75);
    
    for (int i = 0; i < q->rear+1; i++)
    {
        printf("The value at index %d is %d\n",i,peek(q,i));
    }
    
    return 0;
}
