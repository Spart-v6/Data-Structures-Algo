#include<stdio.h>
#include<stdlib.h>

typedef struct deque{
    int size;
    int front;
    int rear;
    int * arr;
}deque;

int isFull(deque *q){
    if(q->front == -1 && q->rear == q->size-1)
        return 1;
    else
        return 0;
}
int isEmpty(deque *q){
    if(q->front == q->rear)
        return 1; 
    else
        return 0;
}

void enqueueL(deque *q,int data){
    if(isFull(q))
        printf("Queue is full! \n");
    else{
        printf("Pushing %d element\n",data);
        q->front--;
        q->arr[q->front] = data;
    }
}
void enqueueR(deque *q,int data){
    if(isFull(q))
        printf("Queue is full! \n");
    else{
        printf("Pushing %d element\n",data);
        q->rear++;
        q->arr[q->rear] = data;
    }
}
int dequeueL(deque *q){
    int a;
    if(isEmpty(q))
        printf("Queue underflow\n");
    else{
        a = q->arr[q->front];
        q->front++;
    }
    return a;
}
int dequeueR(deque *q){
    int a;
    if(isEmpty(q))
        printf("Queue underflow\n");
    else{
        a = q->arr[q->rear];
        q->rear--;
    }
    return a;
}

// void display(deque *q){
//     for(int i=0 ; i< q->rear+1; i++){
//         printf("%d\n",q->arr[i]);
//     }
// }

int main(){
    deque *q = (deque *) malloc(sizeof(deque));
    q->size = 100;
    q->front = q->rear = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    enqueueL(q,20);
    enqueueL(q,30);
    enqueueL(q,10);
    enqueueL(q,23);
    enqueueR(q,23);

    // printf("Popped out %d \n",dequeueL(q));

    return 0;
}


/* IMP:
deque - Double Ended Queue
Insertion can take place from Front as well as rear
Deletion can take place from Front as well as rear
*/