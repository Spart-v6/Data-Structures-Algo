#include<bits/stdc++.h>
using namespace std;

/* check the number is palindrome or not if it is palindrome 
print Yes else No..

input : in first line Take T number of tast cases 
each test cases conatin n number.

output: if number is palindrome print Yes else No.

logic : use rev variable to calculate reverse initially it is 0 
extracted last number is added in rev then after in next itearation 
we have to add another extracted last number for adding this number 
we have to multiply 10 with rev number to add another extracted last number 
*/

bool checkpalindrome(int N){
	int num=N;
	int rem=0,rev,p=N;
	bool flag=false;

	while(p!=0){  
	  rem = p % 10;
	  rev = (rev*10) + rem; 
	  p=p/10;
	}
	 return rev==num;
}

int main(){
	int t;
	cin>>t;
  while(t--){
  	int n;
  	cin>>n;
    if(checkpalindrome(n)){
    	cout<<"Yes\n";
    }
    else cout<<"No\n";
  }
  return 0;
}



