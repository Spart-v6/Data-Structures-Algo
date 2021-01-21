#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node * create(){
    int x;
    struct node * newNode = (struct node *) malloc (sizeof(struct node));
    printf("Enter data (-1 for NO node): \n");
    scanf("%d",&x);

    if(x == -1)
        return 0;
 
    else{
        newNode->data = x;
        printf("Enter the left child of %d \n",x);
        newNode->left = create();
        printf("Enter the right child of %d \n",x);
        newNode->right = create();
    }
    return newNode; //for root node
}

int main(){
    struct node * root = 0;
    root = create();
    return 0;
}
