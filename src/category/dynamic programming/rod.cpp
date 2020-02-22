/**
 * Problem: Max profit in cutting rod of different lengths.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Bottom up Approach
int maxPriceRodCut(int rod_len, int* arr,int* dp){
    if(rod_len<=0){
        return 0;
    }
    
    if(dp[rod_len]!=-1){
        return dp[rod_len];
    }
    
    // Recursion
    for(int i=1;i<=rod_len;i++){
        dp[rod_len] = max(dp[rod_len],arr[i]+maxPriceRodCut(rod_len-i,arr,dp));
    }
    return dp[rod_len];
}

// Top down Approach
int maxPriceRodCutDP(int rod_len, int* arr,int* dp){
   // base case
   dp[0] = 0;
   dp[1] = arr[1];
   
   // Calculates max price for each rod_length
   for(int i=2;i<=rod_len;i++){
       // For current rod length, calculate max profit by taking each case before it.
       for(int j=1;j<=i;j++){
           dp[i] = max(dp[i], arr[j] + dp[i-j]);
       }
   }
   
   return dp[rod_len];
}



void resetDP(int dp[100]){
    for(int i=0;i<100;i++){
        dp[i] = -1;
        }
}


 
int main() {
    int len;
    cin>>len;
    int arr[len+1];
    for(int i=1;i<=len;i++){
        cin>>arr[i];
    }
    int dp[100];
    resetDP(dp);
    int ans = maxPriceRodCut(len,arr,dp);
    cout<<ans<<endl;
    
    resetDP(dp);
    ans = maxPriceRodCutDP(len,arr,dp);
    cout<<ans;
    
	return 0;
}