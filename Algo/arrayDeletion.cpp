#include<iostream>
using namespace std;

int main()
{
    int a[10],size,pos;
    int item;
    cout<<"Enter the size of array\n";
    cin>>size;

    int arrSize = sizeof(a)/sizeof(a[0]); 

    //- Applying pro move#1
    if(size>arrSize){
        cout<<"Size limit exceeded!! ";
    }
    else{
    cout<<"Enter the elements: \n";
    for(int i = 0; i<size ; i++)
    {
        cin>>a[i];
    }

    //-Applying pro move#2
    cout<<"Enter the position to delete the element: \n";
    cin>>pos;
    if(pos<=0 || pos>size){
        cout<<"That's invalid position u noob";
    }

    else{
        item = a[pos-1]; //-just to print the deleted element at last
        for(int i = pos-1; i<size-1; i++){
            a[i] = a[i+1];
        }
        size--; //-shortens the size of array after deleting a element
    }

    cout<<"Printing the new array: \n";
    for(int j=0;j<size;j++){
        cout<<a[j]<<"   ";
    }
    cout<<"\nDeleted element is: "<<item;
    }







    //- Noob way
    // int a[5] = {10,20,30,40,50};
    // int pos,i;
    // cout<<"Enter the position of element to be deleted: \n";
    // cin>>pos;
    // for(i=pos;i<5;i++){
    //     a[i] = a[i+1];  //-Shifting elements to left
    // }

    // //- Displaying the array
    // for(i=0;i<4;i++) //- 4 as one element is deleted
    // {
    //     cout<<a[i]<<"  ";
    // }
    return 0;
}
