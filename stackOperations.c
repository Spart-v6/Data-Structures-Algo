#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *s,int value){
    if(isFull(s)){
        printf("\nStack Overflow! %d cannot be entered in stack\n",value);
    }
    else{
        s->top++; //increment the top and..
        s->arr[s->top] = value; // ..and put the value in the array
    }
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("\nStack Underflow!\n");
        return -1;
    }
    else{
        int value = s->arr[s->top]; //stored the top value which is gonna get deleted
        s->top--; //decremented the top. Next time m gonna OVERRIDE THE VALUE of the item which got deleted (not deleted btw)
        return value;
    }
}

int peek(struct stack *s , int i){
    int pos = s->top-i+1;
    if(pos<0){
        printf("Invalid position");
        return -1;
    }
    else{
        return s->arr[pos];
    }
}

int stackTop(struct stack *s){
    return s->arr[s->top];
}
int stackBottom(struct stack *s){
    return s->arr[0];
}

int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size= 5;
    s->top= -1;
    s->arr = (int *) malloc (s->size * sizeof(int));
    printf("Stack is created succcesfully\n");
    printf("\n=====================\n");
    printf("|  Before, Empty: %d\n",isEmpty(s));
    printf("|  Before, Full: %d\n",isFull(s));
    printf("=====================\n");

    push(s,45);
    push(s,35);
    push(s,16);
    push(s,67);
    push(s,37);
    
    for (int j = 1; j <= s->top+1; j++)
    {
        printf("The value at index %d is %d\n",j,peek(s,j));
    }
    


    // printf("Popped out %d element\n",pop(s));// pops out last element (Follows Last in First Out)
    // printf("Popped out %d element\n",pop(s));
    // printf("Popped out %d element\n",pop(s));
    // printf("Popped out %d element\n",pop(s));
    // printf("Popped out %d element\n",pop(s));
    // printf("Popped out %d element\n",pop(s));// can't pop more as stack is empty now

    printf("\n=====================\n");
    printf("|  After, Empty: %d\n",isEmpty(s));
    printf("|  After, Full: %d\n",isFull(s));
    printf("=====================\n");

    return 0;
}
