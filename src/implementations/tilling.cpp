/**
 * Problem: Tilling 2 - HackerBlocks
 * n*m grid. Find ways to place m*1 tiles.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
const long long MODULO = pow(10,9) + 7;

// Top down
// n = width ; m = height
int tiling(int n, int m, int* dp){
    // 3 base cases
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==m){
        return 2;
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    
    dp[n] = ((tiling(n-1,m,dp))%MODULO + (tiling(n-m,m,dp))%MODULO)%MODULO;
    return dp[n];
}

void resetDp(int* dp){
    for(int i=0;i<=100001;i++){
        dp[i] = -1;
    }
}

int main() {
    int t;
    cin>>t;
    int n,m;
    int dp[100001];
    resetDp(dp);
    int ans;
    while(t--){
        
        cin>>n>>m;
        ans = tiling(n,m, dp);
        cout<<ans<<endl;
        resetDp(dp);
    }
    
    
    
    
	return 0;
}