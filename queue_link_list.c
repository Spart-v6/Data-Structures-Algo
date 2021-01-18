#include<stdio.h>
#include<stdlib.h>

//global variables
struct Node * f = NULL;
struct Node * r = NULL;

struct Node{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}

void enQueue(int val){
    struct Node* n = (struct Node *) malloc(sizeof(struct Node));
    if(n == NULL)
        printf("Queue is full!\n");
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){ //-special check
            f = r = n;
        }
        else{
            r->next = n; //now 'r' points to 'n'
            r = n; //and now 'n' name changed to 'r
        }
    }
}

int deQueue(){
    int val = -1; // -1 will be returned signifying tht value not found!
    struct Node * ptr = f;
    if(f == NULL)
        printf("Queue Empty\n");
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}


int main(){
    linkedlistTraversal(f);
    printf("Removing element %d\n",deQueue());
    enQueue(34);
    enQueue(64);
    enQueue(75);
    linkedlistTraversal(f);
    printf("Removing element %d\n",deQueue());
    return 0;
}


//if u don't make global variables then copy of them will be sent to their resp. fxns and the fxns won't return the true value. So make them global and then u can use them anywhere + can change their original state too