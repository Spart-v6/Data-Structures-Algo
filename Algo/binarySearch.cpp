// !Prerequisite : The array must be sorted

#include<iostream>
using namespace std;

int binarySearch(int arr[],int numberOfElements,int data)
{ 
    int l = 0;
    int r = numberOfElements-1 ; 
    int ans, mid;

    while(l<=r){
        mid = (l+r)/2;
        if(data == arr[mid])
        {
            ans = mid;
            break;
        }
        else if(data < arr[mid])
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ans+1;
}

int main()
{
    int array[10] = {10,20,30,40,50,60,70,80,90,100};
    int data;
    cout<<"Enter the element to be searched: \n";
    cin>>data;
    int size = sizeof(array)/sizeof(int);
    int result = binarySearch(array,size,data);
    cout<<"Item found at index "<<result;
    return 0;
}
