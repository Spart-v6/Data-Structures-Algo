#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
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

void push(struct stack *s, char value){
    if(isFull(s))
        printf("\nStack Overflow! %c cannot be entered in stack\n",value);

    else{
        s->top++; //increment the top and..
        s->arr[s->top] = value; // ..and put the value in the array
    }
}

char pop(struct stack *s){
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

void reverse(struct stack *s,char * str){
    int n = strlen(str);

    for (int i = 0; i < n; i++)  
        push(s, str[i]);  
  
    for (int i = 0; i < n; i++)  
        str[i] = pop(s);  
}


int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size= 100;
    s->top= -1;
    s->arr = (char *) malloc (s->size * sizeof(char));
    

    char str[] = "hello world";
    reverse(s,str);
    printf("The reversed string is %s",str);
    
    return 0;
}
