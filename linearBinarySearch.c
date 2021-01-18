#include<stdio.h>

int linearSearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    low = 0;
    high = size-1;

    while(low<=high){

        mid = (low+high)/2;
        if(arr[mid] == element)
            return mid;
        if(arr[mid] < element)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;

}

int main()
{
    // int arr[] = {234,546,756,453,876,91,23,456,897}; //-For linear search (unsorted array)
    int arr[]= {34,56,78,90,101,123,234,345,456}; //-for binary search (Array must be sorted!)

    int size = sizeof(arr) / sizeof(int);
    int element = 123;
    // int found = linearSearch(arr,size,element);
    int found = binarySearch(arr,size,element);
    printf("The element %d was found at %d location",element,found);
    return 0;
}
