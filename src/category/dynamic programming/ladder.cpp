/**
 * Problem: Going up the ladder of n steps. 
 * @parameter {int} n - number of steps
 * @parameter {int} k - number of steps that could be taken at a time
 * @returns {int} ans - number of ways of reaching nth step
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Top Down Solution
int numberOfStepsTopDown(int steps, int* dp, int k){
    
    if(steps<0){
        return 0;
    }

    //Standing on ground
    if(steps==0){
        return 1;
    }
    
    if(dp[steps]!=-1){
        return dp[steps];
    }
    
    dp[steps] = 0;
    for(int i=1;i<=k;i++){
        dp[steps] += numberOfStepsTopDown(steps-i,dp, k);
    }
    return dp[steps];
}

// Bottom Up Solution
// Time Complexity: O(n.k)
int numberOfStepsBottomUp(int steps,int* dp, int k){
    dp[0] = 1;
    for(int i=1;i<=steps;i++){
        dp[i] = 0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
            }
        }
        
    }
    return dp[steps];
    
}

// Bottom Up Solution 
// Not working currently.
// TODO: Fix ans, algo slightly wrong.
// Time Complexity: O(n)
int numberOfStepsBottomUpOptimal(int steps,int* dp, int k){
    dp[0] = 1;
    for(int i=1;i<=steps;i++){
        dp[i] = 0;
        
        //TODO: Fix this 
        if(i-k-1>=0){
            dp[i] = 2*dp[i-1] - dp[i-k-1];
        }else{
            dp[i] = 2*dp[i-1];
        }
    }
    return dp[steps];
    
}

void resetDp(int* dp){
    for(int i=0;i<1000;i++){
        dp[i] = -1;
    }
}

int main() {
    int n,k;
    cin>>n>>k;
    
    int dp[1000];
    resetDp(dp);
    
    int ans = numberOfStepsTopDown(n,dp,k);
    resetDp(dp);
    int ans2 = numberOfStepsBottomUp(n,dp,k);
    resetDp(dp);
    int ans3 = numberOfStepsBottomUpOptimal(n,dp,k);
    
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    
    
	return 0;
}