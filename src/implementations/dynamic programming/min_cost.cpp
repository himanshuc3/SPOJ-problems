/**
 * Problem: Calculate minimum cost reaching last point in grid.
 *          Only moves right and down.         
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Top down Approach
int minCost(int grid[][100],int m, int n,int dp[][100]){
    // base case
    dp[0][0] = grid[0][0];
    // fill the first row
    for(int c=1;c<n;c++){
        dp[0][c] =  dp[0][c-1] + grid[0][c];
    }
    // fill the first column
    for(int r=1;r<m;r++){
        dp[r][0] =  dp[r-1][0] + grid[r][0];
    }
    
    for(int r=1;r<m;r++){
        for(int c=1;c<n;c++){
            dp[r][c] = grid[r][c] + min(dp[r-1][c],dp[r][c-1]);
        }
    }
    return dp[m-1][n-1];
}



void resetDP(int dp[][100]){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            
        dp[i][j] = -1;
        }
    }
}


 
int main() {
    int grid[][100] = {
        {1,2,3},
        {4,8,2},
        {1,5,3}
    };
    int dp[100][100];
    resetDP(dp);
    int ans = minCost(grid,3,3,dp);
    cout<<ans<<endl;
    
    // resetDP(dp);
    // ans = minimumStepsDP(num,dp);
    // cout<<ans;
    
	return 0;
}