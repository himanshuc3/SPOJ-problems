/**
 * Problem: 0-1 Knapsack. 
 * 2D - DP problem.
 * NOTE: In bounded knapsack we can take infinite number of items. So, there is only 1 change
 * in inclusion variable, change n-1 to n because now we can take the same item again. Anyway, we are
 * going to exclude it in exclusion variable.
 * 
 */
#include<bits/stdc++.h>
using namespace std;


// Recursive
int recursiveKnapsack(int weights[],int prices[], int n,int weightOfSack){
    // No items left or no weight left
    if(n==0||weightOfSack==0){
        return 0;
    }
    
    //Including item
    //Assuming prices to be min for inclusion and exclusion
    int inclusion=0, exclusion=0;
    
    // Starting from the end
    if(weights[n-1]<=weightOfSack){
    inclusion = prices[n-1] + recursiveKnapsack(weights,prices,n-1,weightOfSack-weights[n-1]);
    }
    
    //Excluding item
    exclusion = 0 + recursiveKnapsack(weights,prices,n-1,weightOfSack);
    return max(inclusion,exclusion);
    
}


// Bottom Up Solution
// dp[][] consists of weight for cloumn and current item from start stands for row.
int BottomUp(int weights[], int prices[], int n, int weightOfSack,int dp[][100]){
    
    
    for(int i=0;i<=n;i++){
        for(int currentWeight=0;currentWeight<=weightOfSack;currentWeight++){
            if(i==0||currentWeight==0){
                dp[i][currentWeight]=0;
            }else{
                int inc=0,exc=0;
                if(weights[i-1]<=currentWeight){
                    // prices[i-1] is the price of the current item.
                    // prices[] and weights[] are 0 indexed and dp[][] is kind
                    // of 1 indexed.
                    inc = prices[i-1] + dp[i-1][currentWeight-weights[i-1]];
                }
                // Excluding current item and taking previous item with given currentWeight.
                // That denotes max value of item 1 at that weight.
                exc = dp[i-1][currentWeight];
                dp[i][currentWeight] = max(inc,exc);
            }
        }
    }
    return dp[n][weightOfSack];
}


void resetDp(int dp[][100]){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j] = -1;
        }
    }
}



int main() {
    int weights[] = {2,2,3,1};
    int prices[] = {5,20,20,10};
    int n=4;
    int weightOfSack = 5;
    int dp[100][100];
    resetDp(dp);
    
    int maxProfit = recursiveKnapsack(weights,prices,n,weightOfSack);
    int maxProfit2 = BottomUp(weights,prices,n,weightOfSack,dp);
    cout<<maxProfit<<endl;
    cout<<maxProfit2<<endl;
    
    
    
    
	return 0;
}