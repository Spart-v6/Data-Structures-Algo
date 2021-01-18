#include <stdio.h>
#define SIZE 10

int ar[SIZE];
int top1 = -1;
int top2 = SIZE;

//PUSH
void push_stack1(int data)
{
    if (top1 < top2 - 1)
        ar[top1++] = data;
    else
        printf("Stack full... Cannot Push\n");
}
void push_stack2(int data)
{
    if (top1 < top2 - 1)
        ar[top2--] = data;
    else
        printf("Stack is full.. Cannot Push\n");
}

//POP
void pop_stack1()
{
    if (top1 >= 0){
        int popped_value = ar[top1--];
        printf("%d is being popped from Stack 1\n", popped_value);
    }
    else
        printf("Stack is empty! Cannot Pop\n");
}
void pop_stack2()
{
    if (top2 < SIZE){
        int popped_value = ar[top2++];
        printf("%d is being popped from Stack 2\n", popped_value);
    }
    else
        printf("Stack Empty! Cannot Pop\n");
}

//printing stacks
void print_stack1()
{
    for (int i = top1; i >= 0; --i)
    {
        printf("[ %d ] ", ar[i]);
    }
    printf("\n");
}
void print_stack2()
{
    for (int i = top2; i < SIZE; i++)
    {
        printf("[ %d ] ", ar[i]);
    }
    printf("\n");
}

int main()
{
    int ar[SIZE];
    int num_of_ele;

    for (int i = 0; i <= 2; i++)
    {
        push_stack1(i);
        printf("pushed elem in stack 1 : %d\n", i);
    }
    for (int i = 0; i <= 2; i++)
    {
        push_stack2(i);
        printf("pushed elem in stack 2 : %d\n", i);
    }

    print_stack1();
    print_stack2();

    //pop elements frm stack 1
    // num_of_ele = top1 + 1;
    // while (num_of_ele)
    // {
    //     pop_stack1();
    //     --num_of_ele;
    // }

    return 0;
}