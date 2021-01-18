#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;  //-now it will point to another list (and another one)
    } 
}
int countNodes(struct Node * ptr){
    int count = 0;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    
    //- Allocate memory for nodes in linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));


    //-Linking first and second nodes
    head ->data = 19;
    head ->next = second;

    //- Linking second and third nodes
    second->data = 29;
    second->next = third;

    //- Now assigning value to third and pointing it to NULL and terminate it
    third->data= 2299;
    third->next= NULL;

    linkedlistTraversal(head);
    printf("%d nodes\n",countNodes(head));
    return 0;
}
