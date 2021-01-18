#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define v 5

typedef struct stack{
    int size;
    int top;
    int *arr; 
}stack;

int isEmpty(stack *ptr){
    if(ptr->top == -1) return 1;
    return 0;
}

int isFull(stack *ptr){
    if(ptr->top == ptr->size-1) return 1;
    return 0;
}

void push(stack *s,int value){
    if(isFull(s))
        printf("\nStack Overflow! %d cannot be entered in stack\n",value);

    else{
        // printf("Pushed %d\n",value);
        s->top++; //increment the top and..
        s->arr[s->top] = value; // ..and put the value in the array
    }
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("\nStack Underflow!\n");
        return -1;
    }
    else{
        int value = s->arr[s->top]; //stored the top value which is gonna get deleted
        s->top--; //decremented the top. Next time m gonna OVERRIDE THE VALUE of the item which got deleted (not deleted btw)
        return value;
    }
}

void dfs(int arr[v][v],int src, stack * s){
    int Visited[v] = {0,0,0,0,0}; //coz 5 vertex r there in graph
    int node;
    push(s,src); //pushed the starting node..
    Visited[src] = 1; //coz the source will be already be visited kyuki start hi vhi se ho rha hai

    node = pop(s);
    printf("%d -> ",node);

    while(true){

        for(int i =0; i<v; i++){
            if(arr[node][i] == 1 && Visited[i] == 0){ 
            //  it checks whether there's a root which exists meanas is there any adjacent node is there or not
            //  it checks whether the node is visited or not  
                Visited[i] = 1; //if visited turn it value to 1
                push(s,i); //and push that node to queue
            }
        }
        if(isEmpty(s)){
            break; 
        }
        else{
            node = pop(s);
            printf("%d -> ",node);
        }
    }
}

int main(){
    stack *s = (stack *) malloc(sizeof(stack));
    s->size= 100;
    s->top= -1;
    s->arr = (int *) malloc (s->size * sizeof(int)); //array of size 100 is created
    
    int arr[5][5] = {   {0,1,1,1,0},
                        {1,0,0,1,1},
                        {1,0,0,1,0},
                        {1,1,1,0,1},
                        {0,1,0,1,0}};
    printf("\nDepth First Traversal is: \n");
    dfs(arr,0,s);  //src = 0 means start from 0th node

    return 0; 
}