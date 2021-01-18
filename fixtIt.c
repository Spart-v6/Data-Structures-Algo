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


struct Node *mem = NULL;

struct Node insert(int data){
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = mem;
    mem = new_node;
}

int main()
{
    struct Node *head, *second, *third, *fourth;

    //- Allocate memory for nodes in linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));


    //-Linking first and second nodes
    head ->data = 19;
    head ->next = second;

    //- Linking second and third nodes
    second->data = 29;
    second->next = third;

    //- Linking third and fourth nodes
    third->data= 2299;
    third->next= fourth;

    //- Now assigning value to fourth and pointing it to NULL and terminate it
    fourth->data = 123213;
    fourth->next = NULL;

    linkedlistTraversal(head);



    return 0;
}