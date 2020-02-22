// Get the max XOR of 2 numbers between l and r (inclusive).
// Explanation: https://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/
#include <bits/stdc++.h> 
using namespace std; 
  
// method to get maximum xor value in range [L, R] 
int maxXORInRange(int L, int R) 
{ 
    // get xor of limits 
    int LXR = L ^ R; 
  
    //  loop to get msb position of L^R 
    int msbPos = 0; 
    while (LXR) 
    { 
        msbPos++; 
        LXR >>= 1; 
    } 
  
    // construct result by adding 1, 
    // msbPos times 
    int maxXOR = 0; 
    int two = 1; 
    while (msbPos--) 
    { 
        maxXOR += two; 
        two <<= 1; 
    } 
  
    return maxXOR; 
} 
  
//  Driver code to test above methods 
int main() 
{ 
    int l,r;
    cin>>l>>r;
    cout<<maxXORInRange(l, r)<<endl; 
    return 0; 
}