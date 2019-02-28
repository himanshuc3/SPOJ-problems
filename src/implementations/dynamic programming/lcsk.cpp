/**
 * Problem: Mancunian and K-Ordered LCS.
 *          TO-DO: Segmentation fault.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m,n,k;
char a[2005],b[2005];
ll dp[2005][2005][8];

ll lcsk(ll i,ll j, ll k){
    
    if(i==n||j==m){
        return 0;   
    }
    
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    
    ll res = 0;
    if(a[i]==b[j]){
        res = 1 + lcsk(i-1,j-1,k);
    }else{
        if(k>0){
            res = 1+ lcsk(i-1,j-1,k-1);
        }
        res = max(res, lcsk(i,j-1,k));
        res = max(res, lcsk(i-1,j,k));
    }
    dp[i][j][k] = res;
    return res;
}






int main() {
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++){
            for(ll z=0;z<=k;z++){
                dp[i][j][k] = -1;
            }
        }
    }
    cin>>a>>b;
    cin>>k;
    m = strlen(a);
    n = strlen(b);
    
    cout<<lcsk(m,n,k);
    
   
	return 0;
}