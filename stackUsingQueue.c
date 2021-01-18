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
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(queue *q,int data){
    if(isFull(q))
        printf("Stack Overflow\n");
    else{
        printf("Pushing %d element\n",data);
        q->rear ++;
        q->arr[q->rear] = data;
    }
}

int dequeue(queue *q){
    int val = -1; 
    if(isEmpty(q))
        printf("Stack Underflow!\n");
    else{
        val = q->arr[q->rear];
        q->rear--;
    }
    return val;
}

int peek(queue * stack, int i){
    int pos = stack->rear-i;
    if(pos<0){
        printf("Invalid position");
        return -1;
    }
    else{
        return stack->arr[pos];
    }
}

int stackTop(queue *stack){
    return stack->arr[stack->rear];
}

int stackBottom(queue *stack){
    return stack->arr[stack->front];
}

int main(){
    queue *stack = (queue *) malloc(sizeof(queue)); 
    stack->size = 100; 
    stack->front = 0;  //bottom
    stack->rear = -1;  //top
    stack->arr = (int *) malloc (stack->size * sizeof(int));

    enqueue(stack,10);
    enqueue(stack,20);
    enqueue(stack,30);
    printf("Top: %d\n",stackTop(stack));
    printf("Bottom: %d\n",stackBottom(stack));

    for (int j = stack->front; j <= stack->rear; j++)
    {
        printf("The value at index %d is %d\n",j,peek(stack,j));
    }

    return 0;
}
