/**
 * Problem: Cells mitosis.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1000];


ll cellMitosis(ll x, ll y,ll z,ll cells){
    // Bottom up DP
    dp[0] = 0;
    dp[1] = 0;
    
    ll res;
    for(ll i=2;i<=cells;i++){
        if(i&1){
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2] + x + z);
        }else{
            dp[i] = min(dp[i/2] + x,dp[i-1]+y);
        }
    }
    
    return dp[cells];
}

int main() {
    ll x,y,z;
    ll cells;
    cin>>cells;
    cin>>x>>y>>z;
    
    cout<<cellMitosis(x,y,z,cells);
   
	return 0;
}