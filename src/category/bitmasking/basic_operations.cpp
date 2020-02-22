/**
 * Problem: Basic bit operations.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Starting from 0th bit.
bool getIthBit(int n, int i){
    int mask = 1<<i;
    return n&mask;
}

// Sets ith bit of n to 1.
void setIthBit(int &n,int i){
    int mask = 1<<i;
    n = n|mask;
}

// Clears ith bit to 0.
// mask of the form 11110111.
void clearBit(int &n,int i){
    int mask = ~(1<<i);
    n = n&mask;
}
 
int main() {
   int n;
   cin>>n;
   cout<<getIthBit(n,1);
    
    
	return 0;
}