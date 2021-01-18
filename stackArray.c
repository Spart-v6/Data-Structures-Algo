#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
}; 

int isEmpty(struct stack *ptr){
    if(ptr->top = -1){
        return 1;  //means true
    }
    else{
        return 0; //means false
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 10;
    // s.top = -1;
    // s.arr = (int *) malloc (s.size * sizeof(int));

    //-Instead of this ^ .. do this (below)
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc (s->size * sizeof(int));


    // manually pushing elements
    // s->arr[0] = 2;
    // s->top++;

    //checking if stack is empty or not
    if(isEmpty(s)){
        printf("The stack is empty rn\n");
    }
    else{
        printf("The stack is not empty\n");
    }
    return 0;
}
