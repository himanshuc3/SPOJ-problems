/**
 * Problem: Fibonacci in log(n).
 *          1,1,2,3,5,8,13...
 * 
 */
#include<bits/stdc++.h>
using namespace std;

map<long,long> h;


long fib(int n){
    if(h.count(n)) return h[n];
    
    
    int k = (n&1)? ((n+1)/2): n/2;
    
    h[n] = (n&1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1)):(2*fib(k-1) + fib(k))*fib(k);
    return h[n];
}

int main() {
    int n;
    cin>>n;
    h[0] = 0;
h[1] = 1;
    cout<<fib(n);
    
   
	return 0;
}