/**
 * Problem: Longest common subsequence.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int longestCommonSub(char X[],char Y[]){
    int m = strlen(X);
    int n = strlen(Y);
    int dp[100][100];
    
    // base case
    for(int i=0;i<=m;i++) dp[i][0] = 0;
    for(int j=0;j<=n;j++) dp[0][j] = 0;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
            
}



int main() {
    char str1[100],str2[100];
    cin>>str1>>str2;
    
    cout<<longestCommonSub(str1,str2);
    
   
	return 0;
}