/**
 * Problem: Xor swapping.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Example: a=5,b=7
void xorSwapping(int &a,int &b){
    a = a^b; // a = 5^7
    b = a^b; // b = 5^7^7 = 5
    a = a^b; // a = 5^7^5 = 7
}
 
int main() {
   int a,b;
   cin>>a>>b;
   xorSwapping(a,b);
   cout<<a<<" "<<b;
   
    
	return 0;
}