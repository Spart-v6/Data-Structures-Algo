#include<iostream>
// #include<chrono>
using namespace std;
// using namespace std::chrono; 
// auto start = high_resolution_clock::now(); 
 

void selectionSort(int a[],int n){
    for (int i = 0; i < n-1; i++) //-this for loop is for 'passes'
    { 
        int min = i; //- considering the first element in array as minimum 

        for (int j = i+1; j < n; j++) //-this will compare that element with others to find minimum element(searching!)
        {
            if(a[j] < a[min]){
                min = j;  //-updating min element now
            }
        }
        if(min!=i){
            //-swapping in progess
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        } 
        cout << "Pass: " << endl;
        for (int i = 0; i < n; i++)
    {
        cout<<"["<<a[i]<<"]"<<" ";
    }  
    cout << endl;        
    }

    //-printing the sorted array
    cout<<"Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"["<<a[i]<<"]"<<" ";
    }    
}

int main()
{
    int arr[] = {32, 51, 27, 85, 66, 23, 13, 57};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr,size);

    //-calculating time!
    // auto stop = high_resolution_clock::now(); 

    // cout<<"\nTime taken:\n";
    // auto duration = duration_cast<seconds>(stop - start); 
    // cout << duration.count() << endl; 



    return 0;
}

//  Best case : O(n^2)
//  Worst case : O(n^2)
