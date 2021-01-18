#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
// #include<stack.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *s,char value){
    if(isFull(s)){
        printf("\nStack Overflow! %d cannot be entered in stack\n",value);
    }
    else{
        s->top++; //increment the top and..
        s->arr[s->top] = value; // ..and put the value in the array
    }
}

char pop(struct stack *s){
    if(isEmpty(s)){
        printf("\nStack Underflow!\n");
        return -1;
    }
    else{
        char value = s->arr[s->top]; //stored the top value which is gonna get deleted
        s->top--; //decremented the top. Next time m gonna OVERRIDE THE VALUE of the item which got deleted (not deleted btw)
        return value;
    }
}

int stackTop(struct stack *s){
    return s->arr[s->top];
}


int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;  //true
    else
        return 0; //false
}

int precedence(char ch){
    //- Took only 4 operators!
    
    if(ch == '^')
        return 4; //highest of highest precedence
    if(ch == '*' || ch == '/')
        return 3; //the highest precendence
    else if(ch == '+' || ch == '-')
        return 2; //a little low precedence
    else
        return 0; //lowest precendence
}

char * infixToPostfix(char * infix){
    struct stack * s = (struct stack *) malloc (sizeof(struct stack));  //created instance of stack
    s->size = 100;
    s->top = -1;
    s->arr = (char *) malloc (s->size * sizeof(char));

    char * postFix = (char *) malloc (strlen(infix)+1 * sizeof(char)); //made postFix character array size same as of infix 
    int i = 0; // to track infix traversal
    int j = 0; // to append in postfix

    while (infix[i] != '\0')   
    {
        if(!isOperator(infix[i])){
            postFix[j] = infix[i];
            i++,j++;

        }
        // else if(infix[i] == '('){
        //     push(s,'(');
        // }
        // else if(infix[i] == ')'){
        //     while(stackTop(s)!= '\0' && stackTop(s)!= '('){
        //         postFix[j] = pop(s);
        //         j++;
        //     }
        //     if(stackTop(s) == '('){
        //         char c = stackTop(s);
        //         pop(s);
        //     }
        // }
        else{
            if( precedence(infix[i]) > precedence(stackTop(s)) ){
                push(s,infix[i]);
                i++; //now look for (another one) character from infix
            }
            else{
                postFix[j] = pop(s); //if ur precedence does not match then pop it from stack and just write it in postfix expression
                j++;
            }
        }
    }
    //now few items maybe left in stack.. so for that:
    while (!isEmpty(s))
    {
        postFix[j] = pop(s); //just removing all left over elements from stack and putting them to postfix
        j++;
    }
    postFix[j] = '\0'; //null character 
    return postFix; 
}

int main()
{
    char * infix = "a+b*(c^d-e)^(f+g*h)-i";
    printf("PostFix : %s" , infixToPostfix(infix));
    
    return 0;
}
