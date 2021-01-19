#include<iostream>
using namespace std;

int main()
{   
    //- dynamically entered the size of array
    int* array = NULL;
    int sizeOfArray,j; 
    bool f = false;
    cout<<"How many total elements are to be stored in array? \n";
    cin>>sizeOfArray;
    array = new int[sizeOfArray];

    //- entering the elements in array
    cout<<"Enter the numbers now:\n";
    for(int i=0; i<sizeOfArray; i++)
    {
        cin>>array[i];
    }

    //- applying linear search algo
    int checkElement;
    cout<<"\nEnter the element to see it's location: \n";
    cin>>checkElement;

    for(j=0; j<sizeOfArray; j++){
        if(checkElement == array[j]){
            f = true;
            j++;
            break;
        }
    }

    if(f){
        cout<<"Element found at "<<j;
    }
    else{
        cout<<"Not found !";
    }
    delete [] array;
    array = NULL;

    return 0;
}

// {10,20,30,40,50,607,07....}