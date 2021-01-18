#include <iostream> 
using namespace std; 
  
void towerOfHanoi(int n, char beg, char aux, char end)  
{  
    if (n >= 1)  
    {  
        towerOfHanoi(n - 1, beg, end, aux);  
        cout <<beg<<" to "<<end<<endl;  
        towerOfHanoi(n - 1, aux, beg, end);  
    }  
}  

int main()  
{  
    int n = 4;   
    towerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;  
}