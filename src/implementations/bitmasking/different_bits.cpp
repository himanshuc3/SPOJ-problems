/**
 * Problem: Number of different bits in n1 and n2.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Check number of different bits between n1 and n2. 
int differentBits(int n1,int n2){
    int n = n1^n2;
    
    //count set bits now in n.
    int count = 0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}

 
int main() {
   int n1,n2;
   cin>>n1>>n2;
   cout<<differentBits(n1,n2);
    
	return 0;
}