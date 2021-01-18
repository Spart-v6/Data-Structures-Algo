#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node * left, * right;
}node;

//Traversal
void inOrder(node * root){
  if(root != NULL){
    inOrder(root->left);
    printf("%d -> ",root->data);
    inOrder(root->right);
  }
}

//Create node
node * createNode(int item){
  node * newNode = (node * ) malloc(sizeof(node));
  newNode->data = item;
  newNode->left = newNode->right = NULL;
  return newNode;
}

//Search
node * search(node * root, int item){
  if(root == NULL || root->data == item)  return root;
  else if(item < root->data)
    return search(root->left,item);
  else
    return search(root->right,item);
}

//Insert Node
node * insert(node * root, int item){
  if(root == NULL)
    return createNode(item);
  else if(item < root->data)
    root->left = insert(root->left,item);
  else
    root->right = insert(root->right,item);

  return root;
}

//find min. for deletion (2 childrens)
node * inOrderSuccessor(node * root){
  if(root == NULL) return root;
  else if(root->left!= NULL)
    return inOrderSuccessor(root->left);
  return root;
}

//Delete Node
node * delete(node * root, int item){
  //Return if tree = empty
  if(root == NULL) return root;
  if(item < root->data)
    root->left = delete(root->left,item);
  else if(item > root->data)
    root->right = delete(root->right,item);
  else{
    //No children
    if(root->left == NULL && root->right == NULL){
      free(root);
      return NULL;
    }
    //One child
    else if(root->left == NULL || root->right == NULL){
      node * temp;
      if(root->left == NULL) //left child nahi hai means right ko store kar lo temp me and fir root ko delete kro and right child jo temp me stored hai usko uske grand parent ke sath connect kar do which is why we wrote return temp
        temp = root->right;
      else
        temp = root->left;
      free(root);
      return temp;
    }
    //Two children
    else{
      struct node *temp = inOrderSuccessor(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  return root;
}

int main(){
  node * root = NULL;
  printf("\n=========================\n");
  printf("Inorder Traversal of tree\n");
  root = createNode(25);
  insert(root,10);
  insert(root,5);
  insert(root,3);
  insert(root,6);
  insert(root,20);
  insert(root,15);
  insert(root,13);
  insert(root,21);
  insert(root,35);
  insert(root,40);
  inOrder(root);

  int found,deleteItem;
  printf("\n\nEnter element to search in tree:  ");
  scanf("%d",&found);
  if(search(root,found))
    printf("%d element found in tree!\n",found);
  else
    printf("%d Not found!\n",found);
  
  printf("\nEnter the item to be deleted from tree:  ");
  scanf("%d",&deleteItem);
  if(search(root,deleteItem)){
    printf("Deleting %d from tree...\n",deleteItem);
    delete(root,deleteItem);
    printf("\nTraversal after deleting %d from tree\n",deleteItem);
    inOrder(root);
  }
  else
    printf("\nThe element to be deleted is not found in tree");

  printf("\n=========================\n");

  return 0;
}