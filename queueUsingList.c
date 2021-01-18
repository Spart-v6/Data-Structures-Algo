#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}list;

typedef struct queue{
    list *front;
    list *rear;
}queue;

int isEmpty(queue *q){
    return (q->rear == NULL);
}

void enqueue(queue *q, int value){
    list *newNode = malloc(sizeof(list));
    newNode->data = value;
    newNode->next = NULL;
    if(!isEmpty(q))
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    else
        q->front = q->rear = newNode;
}

int dequeue(queue *q){
    list *temp;
    int n = q->front->data;
    temp = q->front;
    q->front = q->front->next;
    free(temp);
    return(n);
}

void display(list *head){
    while(head!=NULL){
        printf("%d ->  ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    queue *q = malloc(sizeof(queue));
    q->front = q->rear = NULL;
    printf("\n===============================\n");
    printf("Initial queue\n");
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    display(q->front);
    printf("\nFront pointer: %d\n",q->front->data);
    printf("Rear pointer: %d\n",q->rear->data);
    printf("\nDequeuing element from queue\n");
    dequeue(q);
    display(q->front);
    printf("Front pointer: %d\n",q->front->data);
    printf("Rear pointer: %d\n",q->rear->data);
    printf("\n===============================\n");
    return 0;
}