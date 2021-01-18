#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    if(isFull(s))
        printf("\nStack Overflow! %d cannot be entered in stack\n",value);

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

// void reverse(struct stack *s,char str[]){
//     int n = strlen(str);
//     if(n == 0 || n ==1)
//         return;
//     else{
//         reverse(s,str[n-1]);
//     }
// }


int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size= 5;
    s->top= -1;
    s->arr = (int *) malloc (s->size * sizeof(int));
    

    char str[] = "yoo!";
    reverse(s,str);
    printf("The reversed string is %s",str);
    

    return 0;
}
