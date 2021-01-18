#include<stdio.h>

void display(int arr[], int n){
    //- Traversal
    
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
}

int deleteElement(int arr[],int size, int index){
    //-Deletion

    for (int i = index; i <size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[100] = {34,67,43,78,69,34};
    int size = 6,element = 45,index = 1;
    display(arr,size);
    deleteElement(arr,size,index);
    size--;
    printf("\n\n");
    display(arr,size);
    return 0;
}
