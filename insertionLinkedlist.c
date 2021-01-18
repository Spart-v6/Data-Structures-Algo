#include<stdio.h>
#include<stdlib.h>

//-This is a self referencing structure
struct Node{
    int data;
    struct Node *next;
}; 

//-Traversal!
void linkedlistTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;  //-now it will point to another list (and another one)
    }
}

//? We have 4 ways to insert in Linked Lists:
//* 1. Insert at first
//* 2. Insert in between
//* 3. Insert at end
//* 4. Insert after a node


//-Inserting at first
struct Node * insertAtFirst(struct Node * head, int data){
    struct Node *ptr = (struct Node *)malloc (sizeof(struct Node)); //-got memory from heap!
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//-Inserting in between
struct Node * insertAtIndex(struct Node * head, int data,int index){
    struct Node *ptr = (struct Node *)malloc (sizeof(struct Node)); //-got memory from heap!
    struct Node * p = head;
    int i =0;
 
    while (i!=index-1)  
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//-Insert at end
struct Node * insertAtEnd(struct Node * head, int data){
    struct Node *ptr = (struct Node *)malloc (sizeof(struct Node)); //-got memory from heap!
    ptr->data = data;

    struct Node * p = head;

    while (p->next!= NULL)
    {
        p = p->next;   
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//-Insert after a node
struct Node * insertAfterNode(struct Node * head,struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc (sizeof(struct Node)); //-got memory from heap!
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    
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

    printf("Before insertion: \n");
    linkedlistTraversal(head);

    printf("\nAfter insertion:\n");
    // head = insertAtFirst(head,69);
    // head = insertAtIndex(head,6339,2);
    // head = insertAtEnd(head,56768000);
    head = insertAfterNode(head,second,10);

    linkedlistTraversal(head);

    return 0;
}
