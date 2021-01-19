#include<iostream>
using namespace std; 

void insertionSort(int a[],int n){
    int temp,j;
    for (int i = 1; i < n; i++) //till no. of passes and incremenent this loop for unsorted array
    {
        temp = a[i]; //assigning first element of unsorted array as temp
        j = i-1;  // decrement this loop for sorted array!
        
        while (j>=0 && a[j]>temp) //comparisons r done here
        {
            a[j+1] = a[j]; //right shift elements
            j--;
        }
        a[j+1] = temp; //correct position found.. replace it then

        cout << "Pass: " << endl;
        for (int i = 0; i < n; i++)
    {
        cout<<a[i] << endl;
    }
    }
    cout<<"Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i] << endl;
    }
}
int main()
{
    int arr[] = {32, 51, 27, 85, 66, 23 ,13, 57};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<size;
    insertionSort(arr,size);
    return 0;
}

//? Best case- O(n) : when array is already in ascending order and at least we need to traverse through array so 'n'
//? Worst case- O(n^2) : when array is in descending order and for that we'll use 2 for loops .. so n^2