#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void llTraversal(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("Element : %d \n",ptr->data);
        // printf("Address : 0x%x \n",ptr);

        ptr = ptr->next;

    }while(ptr!=head);
}

struct Node * llInsertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next!= head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
    

}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *) malloc (sizeof(struct Node));
    second = (struct Node *) malloc (sizeof(struct Node));
    third = (struct Node *) malloc (sizeof(struct Node));
    fourth = (struct Node *) malloc (sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = head;

    printf("Elements before:\n");
    llTraversal(head);

    
    printf("Elements after insertion:\n");
    head = llInsertAtFirst(head,20);
    llTraversal(head);


    return 0;
}
