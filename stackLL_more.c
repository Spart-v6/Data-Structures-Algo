#include<stdio.h>
#include<stdlib.h>

//- Global Variable (came from main)!
struct Node *top = NULL; 

struct Node{
    int data;
    struct Node *next; 
};

void linkedlistTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}

int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

// int isFull(struct Node* top){
//     struct Node * n = (struct Node *) malloc(sizeof(struct Node)); 
//     if(n == NULL){ 
//         return 1;
//     }
//     return 0;
// }

struct Node* push(struct Node* top, int data){
    struct Node * n = (struct Node*) malloc(sizeof(struct Node)); 
    n->data = data; 
    n->next = top; 
    top = n; 
    return top;
}

int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack Underflow!");
    }
    else{
        struct Node * n = tp; 
        top = (tp)->next; 
        int x = n->data; 
        free(n); 
        return x;
    }
}

int peek(int pos){      //-----(1)
    struct Node * ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1; // assuming there's no -ve element in stack 
    }
}

int stackTop(struct Node * top){
    return top->data;
}

int stackBottom(struct Node * top){
    struct Node * p = top;
    while(p->next!=NULL){
        p = p->next;
    }
    return p->data;
}

int main()
{
    top = push(top, 69);
    top = push(top, 10);
    top = push(top, 8);
    top = push(top, 7);
    linkedlistTraversal(top);

    for (int i = 1; i <= 4; i++)
    {
        printf("The element at position %d is %d\n",i,peek(i));  
    }
    
    // printf("The top most element in stack is %d\n",stackTop(top));
    printf("The bottom most element in stack is %d\n",stackBottom(top));

    return 0;
}
/* 
--(1)

peek() :

pos        moves 
1           0
2           1
3           2

means if u want to see what's there in 3rd position then u gotta move 2 times so pos-1

*/