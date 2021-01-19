#include<iostream>
using namespace std;

int main()
{
    int a[7] = {10,30,40,50,60}; 
    int pos,num,i;
    cout<<"Tell us the position and number: \n";
    cin>>pos>>num;
    //? 2 pe insert krna hai 20 
    for(i=4;i>=pos;i--){
        a[i+1] = a[i]; //-Shifting numbers to the right 
    }
    a[pos] = num; //-Overrriding the number at given position
    cout<<"The new array is: \n";
    for(i=0;i<6;i++){
        cout<<a[i]<<"  ";
    }
    return 0;
}
