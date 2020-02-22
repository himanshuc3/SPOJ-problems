/**
 * Problem: Pigeonhole Principle application.
 *          Find the number of subarrays with sum divisible by n;
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Prefix sum acts as frequency array
int numberOfSubArrays(int arr[],int prefixSum[], int n){
    for(int i=0;i<n;i++){
        prefixSum[i] = 0;
    }
    prefixSum[0] = 1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        sum %= n;
        //Making the number positive
        sum = (sum+n)%n;
        
        prefixSum[sum]++;
    }
    
    int ans = 0;
    
    for(int i=0;i<n;i++){
        // nC2
        ans += prefixSum[i]*(prefixSum[i]-1)/2;
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    int prefixSum[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int subArrays = numberOfSubArrays(arr,prefixSum,n);
    cout<<subArrays;
    
    
	return 0;
}