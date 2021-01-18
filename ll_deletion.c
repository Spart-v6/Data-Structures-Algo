#include<stdio.h>
#include<stdlib.h>

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

//Case 1 : Deleting first node 
struct Node * deleteFirst(struct Node *head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Case 2: Deleting the element at a given index (u can't delete first node!)
struct Node * deleteAtIndex(struct Node *head,int index){
    struct Node * ptr = head;
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//Case 3: Deleting from the End
struct Node * deleteAtEnd(struct Node * head){
    struct Node * ptr = head;
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//Case 4: Delete a node with a given data or value or key (kinda similar to case 2)
struct Node * deleteAtValue(struct Node *head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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

    //-First node
    head ->data = 3;
    head ->next = second;

    //-Second node
    second->data = 6;
    second->next = third;

    //-Third node
    third->data= 9;
    third->next= fourth;

    //-Fourth node and points to NULL
    fourth->data= 1;
    fourth->next= NULL;

    printf("Before deletion linked list was: \n");
    linkedlistTraversal(head);


    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    // head = deleteAtEnd(head);
    head = deleteAtValue(head,9);
    printf("After deletion linked list is: \n");
    linkedlistTraversal(head);

    return 0;
}
