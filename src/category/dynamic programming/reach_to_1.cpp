/**
 * Problem: Reach to 1 in minimum number of steps.
 *          Can do division by 2, 3 and reduce by 1.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Bottom up
int minimumSteps(int num, int dp[]){
    if(dp<=0){
        return 0;
    }
    if(num==1){
        return 0;
    }
    
    // Recursive
    if(dp[num]!=-1){
        return dp[num];
    }
    int ans1=INT_MAX,ans2=INT_MAX,ans3 = INT_MAX;
    if(num%2==0){
        ans1 = minimumSteps(num/2,dp);
    }
    if(num%3==0){
        ans2 = minimumSteps(num/3,dp);
    }
    if(num-1>=1){
        ans3 = minimumSteps(num-1,dp);
    }
    
    dp[num] = 1 + min(ans3,min(ans1,ans2));
    return dp[num];
} 

// Top down iterative approach.
int minimumStepsDP(int num, int dp[]){
    //initialize 
    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;
    
    for(int i= 4;i<=num;i++){
        int ans1=INT_MAX,ans2=INT_MAX,ans3 = INT_MAX;
    if(num%2==0){
        ans1 = minimumSteps(num/2,dp);
    }
    if(num%3==0){
        ans2 = minimumSteps(num/3,dp);
    }
    if(num-1>=1){
        ans3 = minimumSteps(num-1,dp);
    }
        dp[num] = 1 + min(ans3,min(ans1,ans2));
    }
    
    return dp[num];
    
}

void resetDP(int dp[]){
    for(int i=0;i<1000;i++){
        dp[i] = -1;
    }
}


 
int main() {
    int num;
    int dp[1000];
    resetDP(dp);
    cin>>num;
    int ans = minimumSteps(num,dp);
    cout<<ans<<endl;
    
    resetDP(dp);
    ans = minimumStepsDP(num,dp);
    cout<<ans;
    
	return 0;
}