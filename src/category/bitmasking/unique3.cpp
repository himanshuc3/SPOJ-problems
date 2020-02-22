/**
 * Problem: All numbers occuring thrice except 1 unique number.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Algorithm: Since there are 3 of all numbers except 1,
//            bits array would contain 3n in each element except
//            for positions of unique number where element would be 3n+1.
int uniqueIII(int* arr, int n){
    // Assuming 32 bits and storing number of set bits accordingly.
    int bits[32] = {0};
    
    // Iterating over arr.
    for(int i=0;i<n;i++){
        
        int temp = arr[i];
        int pos=0;
        // Add set bit to bits[]
        while(temp!=0){
            if(temp&1){
                bits[pos]++;
            }
            temp = temp>>1;
            pos++;
        }
    }
    
    // Forming number
    int formedNumber = 0;
    for(int i=0;i<32;i++){
        bits[i] = bits[i]%3;
        if(bits[i]){
        formedNumber+=pow(2,i);
        }
    }
    return formedNumber;
}




int main() {
    int arr[] = {7,7,3,4,2,4,3,3,4,7};
    int n = 10;
    
    int unique = uniqueIII(arr,n);
    cout<<unique;
    
	return 0;
}