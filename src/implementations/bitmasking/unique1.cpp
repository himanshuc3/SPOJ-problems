/**
 * Problem: An array given in which every element is present twice except 1 number
 *          which is unique. Find that number.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Trick: number ^ number = 0
//        number ^ 0 = number
int unique1(int* arr,int n){
    int ans=arr[0];
    for(int i=1;i<n;i++){
        ans^=arr[i];
    }
    return ans;
}

 
int main() {
   int arr[] = {5,7,4,5,7};
   cout<<unique1(arr,5);
    
	return 0;
}