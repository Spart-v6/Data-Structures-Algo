//? Quick Sort- Also known as Divide and Conqueror algo or Partition-Exchange algo
//* In this i've taken lower bound element as pivot element
 
#include<iostream>
using namespace std;

int partition(int* a,int lb,int ub){
    int pivot = a[lb];
    int start = lb; 
    int end = ub;
    
    while (start<end)
    {
        while(a[start] <= pivot){
            start++;
        }
        while(a[end] > pivot){
            end--;
        }

        if(start < end){
            //- swap(a[start] , a[end])
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    //- if end is greater that ur start then swap end with lower bound (pivot element)!
    //- swap(a[lb] , a[end]) !
    int anotherTemp = a[lb];
    a[lb] = a[end];
    a[end] = anotherTemp;

    return end; //-this will be further used to divide the array into sub array i.e. left array and right array!
}

void quickSort(int a[],int lb,int ub)
{
    int loc;
    if(lb < ub){
        loc = partition(a,lb,ub); //-loc is location- which is ur pivot element (parition fxn gonna return tht)
        quickSort(a,lb,loc-1); //-this contains ur left array from lower bound till location -1 (pivot element -1)
        quickSort(a,loc+1,ub); //-this contains ur right array from location + 1 till ur upper bound!
    } 
}


int main()
{
    int size;
    cout<<"Enter the size of array\n";
    cin>>size;
    int *a = new int(size);
    int lb,ub; 
    cout<<"Enter the elements\n";
    for (int i = 0; i < size; i++){
        cin>>a[i];
    }
    cout<<"Enter lower and upper bound\n";
    cin>>lb>>ub;
    quickSort(a,lb,ub);
    cout<<"Sorted array: \n";
    for (int i = 0; i < size; i++){
        cout<<"["<<a[i]<<"]"<<" ";
    }
    
    return 0;
}

// Best Case : O(n logn)
// Worst Case : O(n^2)
