#include<stdio.h>

void display(int arr[], int n){
    //- Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
}

int insertElement(int arr[],int size, int element, int capacity, int index){
    //-Insertion
    if (size>=capacity)
    {
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;   
}

int main()
{
    int arr[100] = {34,67,43,78,69,34};
    int size = 6,element = 45,index = 1;
    display(arr,size);
    insertElement(arr,size,element,100,index);
    size++;
    printf("\n\n");
    display(arr,size);
    return 0;
}
