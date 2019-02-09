/**
 * Problem: Coins are given. Find minimum number of coins needed for making a particular amount.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Recursive
int recursiveMinimumCoins(int* currency, int currency_length, int amount){
    // Base case
    // If amount = 0, 0 coins needed
    if(amount==0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=0;i<currency_length;i++){
        if(amount-currency[i]>=0){
        ans = min(ans,recursiveMinimumCoins(currency,currency_length,amount - currency[i])+1);  
        }
    }
    return ans;
}



// Bottom Up Solution
int minimumCoinsDP(int* currency, int currency_length, int amount,int* dp){
    dp[0] = 0;
    
    for(int i=1;i<=amount;i++){
        dp[i] = INT_MAX;
        
    }
    
    
    for(int i=1;i<=amount;i++){
        
        for(int j=0;j<currency_length;j++){
            if(currency[j]<=i){
                // Calculating minimum of previous calculated dp value and
                // DP[current_amount - currency_note] + 1 - 1 for that currency_note
                // value when added to current_amount - current_note.
                dp[i] = min(dp[i],dp[i-currency[j]]+1);
            }
        }
    }
    return dp[amount];
}




void resetDp(int* dp){
    for(int i=0;i<1000;i++){
        dp[i] = -1;
    }
}

int main() {
    int us_coins[] = {1,7,10};
    int n=3;
    int amount = 15;
    int dp[1000];
    resetDp(dp);
    
    int ans1 = recursiveMinimumCoins(us_coins,n,amount);
    int ans2 = minimumCoinsDP(us_coins,n,amount, dp);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    
    
    
    
	return 0;
}