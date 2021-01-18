//* | 7 | --> | 8 | --> | 10 | --> | 69  | --> NULL (example) and the bottom element will be 12 and top is 7 

#include<stdio.h>
#include<stdlib.h>

//- Global Variable (came from main)!
struct Node *top = NULL; //initially ur linked list (stack) is empty
 
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

// u can set size limit for it 
// here i haven't set any limit means it's unlimited size 
// so, the stack will be FULL if i'm creating a node and it couldn't be made
int isFull(struct Node* top){
    struct Node * n = (struct Node *) malloc(sizeof(struct Node)); //created memory dynamically
    if(n == NULL){ //if n is NULL it means the memory is not created dynamically means the stack is FULL that's why it happened
        return 1;
    }
    return 0;
}

struct Node* push(struct Node* top, int data){
    if(isFull(top)){
        printf("Stack Overflow!\n");
    }
    else{
        struct Node * n = (struct Node*) malloc(sizeof(struct Node)); //created a node to push
        n->data = data; //sets data
        n->next = top; //sets next part of n to top (u wanna join linked list)
        top = n; //basically incremented top (now top points to n, which is now top)
        return top;
    }
}

int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack Underflow!");
    }
    else{
        struct Node * n = tp; // just to delete n later and top will be safe 
        top = (tp)->next; // (right shifted top in LL or moved down top in stack "visualize it")
        int x = n->data; // to show the popped element
        free(n); // deleted n
        return x;
    }
}

int main()
{

    top = push(top, 69);
    top = push(top, 10);
    top = push(top, 8);
    top = push(top, 7);
    printf("Before\n");
    linkedlistTraversal(top);


    //! top element does not have any relation with main fxn... so it will not change the top value
    //! means if u send ut top to pop fxn and later send another top to pop .. so it will not update/change top in main fxn
    //! in order to do so, just send it's address like int element = pop(&top); and in pop fxn u gotta create pointer of pointer
    //! so just add asterisk in top 

    //* if u don't want to do this shit ^^^^ then do this:
    //* make top as a global variable.. so that if u change top wherever then it will change global top too
    //* change name of top variable in pop fxn as ur global variable name is also same
    //* u can say it will create confusion b/w global variable top and local variable top (of pop fxn) 
    //* so change name of top variable in pop fxn 
    //* top = (tp)->next; and u updated top here

    printf("After\n");
    int element = pop(top);
    printf("Popped element is %d \n",element);

    linkedlistTraversal(top);
    return 0;
}
