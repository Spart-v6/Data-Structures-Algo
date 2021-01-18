#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left, * right;
}tree;

tree * create(){
    int x;
    tree * newNode = (tree *) malloc(sizeof(tree));
    printf("Enter data, -1 for no data\n");
    scanf("%d",&x);

    if(x == -1)
        return 0;
    
    else{
        newNode->data = x;
        printf("Enter the left child of %d\n",x);
        newNode->left = create();
        printf("Enter the right child of %d\n",x);
        newNode->right = create();
    }
    return newNode; //for root    
}

void inOrder(tree * root){ //IMP: Inorder: LEFT ROOT RIGHT
    if(root == 0)
        return;
    else{
        inOrder(root->left);
        printf("%d  ",root->data);
        inOrder(root->right);
    }
}

void preOrder(tree * root){ //IMP: Preorder: ROOT LEFT RIGHT
    if(root == 0)
        return;
    else{
        printf("%d  ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(tree * root){ //IMP: Postorder: LEFT RIGHT ROOT
    if(root == 0)
        return;
    else{
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ",root->data);
    }
}

int main(){
    tree * root = create();
    printf("\nIn-order traversal:\n");
    inOrder(root);
    printf("\nPre-order traversal:\n");
    preOrder(root);
    printf("\nPost-order traversal:\n");
    postOrder(root);

    return 0;
}