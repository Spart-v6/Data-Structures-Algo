#include<stdio.h>
#include<stdlib.h>

typedef struct CircularQueue{
    int r;
    int f; 
    int size;
    int * arr;
}Cqueue;

int isFull(Cqueue * q){
    if((q->r+1)%q->size == q->f)   //-CIRCULAR INCREMENT !!!!
        return 1;
    else
        return 0;
}
int isEmpty(Cqueue * q){
    if(q->r == q->f)   
        return 1;
    else
        return 0;
}

void enqueue(Cqueue* q,int data){
    if(isFull(q))
        printf("Queue overflow!\n"); 
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = data;
        printf("Enqued %d \n",data);
    }
}

int dequeue(Cqueue* q){
    int val = -1;
    if(isEmpty(q))
        printf("Queue underflow! \n");
    else{
        q->f = (q->f+1) % q->size;
        val = q->arr[q->f];
    }
    return val;
}

void display(Cqueue *q){
    int pos = q->f+1;
    for (int i = pos; i < q->r+1 % q->size; i++)
    {
        printf("> %d \n",q->arr[i]);
    }
}


int main(){
    Cqueue q;
    q.size = 5;
    q.f = q.r = 0; //for circular only
    q.arr = (int *) malloc (q.size * sizeof(int));


    enqueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,23);
    enqueue(&q,64);
    printf("Displaying elements after enqueing:\n");
    display(&q);
    printf("Dequed %d element \n",dequeue(&q));
    printf("Dequed %d element \n",dequeue(&q));
    printf("Displaying elements after dequeing:\n");
    display(&q);

    return 0;
}