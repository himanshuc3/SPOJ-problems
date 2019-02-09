/**
 * Problem: Count set bits :)
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(number of bits)
int countSetBits(int n){
    int count = 0;
    while(n!=0){
        if(n&1){
            count++;
        }
            n=n>>1;
    }
    return count;
}

// Time complexity: O(number of set bits)
// Uses n&(n-1) technique. 
// In this technique, last set bit is removed from n.
// So, everytime we remove last set bits untill all set bits are removed.
int countSetBitsFast(int n){
    int count = 0;
    while(n){
        count++;
        // To remember. Though, I know I won't.
        n=n&(n-1);
    }
    return count;
}

bool isOdd(int n){
    return n&1;
}
 
int main() {
   int n;
   cin>>n;
   cout<<countSetBits(n)<<endl;
   cout<<isOdd(n)<<endl;
   cout<<countSetBitsFast(n);
    
	return 0;
}