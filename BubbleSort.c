#include<stdio.h>

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n){
    int temp;
    int flag;
    for (int i = 0; i < n-1; i++)
    {
        flag = 1;
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 0;
            }
        }
        if(flag){
            return;
        }
    }
    
}

int main(){
    int arr[] = {6,2,8,2,78,12,84};
    int n = sizeof(arr)/sizeof(int);

    printf("Before\n");
    printArray(arr,n);

    bubbleSort(arr,n);

    printf("After\n");
    printArray(arr,n);

    return 0;
}