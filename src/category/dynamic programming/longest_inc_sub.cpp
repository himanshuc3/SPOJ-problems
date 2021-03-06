/**
 * Problem: Longest increasing subsequence.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int longestIncSub(int arr[], int n){
    int dp[n];
    for(int i=0;i<n;i++)dp[i] = 1;
    
    
    int best = -1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>=arr[j]){
                int currLen = 1 + dp[j];
                dp[i] = max(dp[i],currLen);
                best = max(best,dp[i]);
            }
        }
    }
    
    return best;
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<longestIncSub(arr,n);
    
   
	return 0;
}