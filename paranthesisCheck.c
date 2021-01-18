#include<stdio.h>
#include<stdlib.h>

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

void push(struct stack *s,char value){
    if(isFull(s)){
        printf("\nStack Overflow! %d cannot be entered in stack\n",value);
    }
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
        char value = s->arr[s->top]; //stored the top value which is gonna get deleted
        s->top--; //decremented the top. Next time m gonna OVERRIDE THE VALUE of the item which got deleted (not deleted btw)
        return value;
    }
}

int parathesisCheck(char * exp){

    //-Initialized the stack
    struct stack *s;
    s->size = 100;
    s->top= -1;
    s->arr = (char *) malloc (s->size * sizeof(char));


    for (int i = 0; i < exp[i]!='\0'; i++)
    {
        if(exp[i] == '('){
            push(s,'(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(s)){
                return 0; //false
            }
            pop(s); //true
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main()
{

    char * exp = "3* (9+ 1)";

    if(parathesisCheck(exp)){
        printf("Parenthesis is matching : Balanced \n");
    }
    else{
        printf("Parenthesis is not matching : Not Balanced \n");
    }
    
    return 0;
}
