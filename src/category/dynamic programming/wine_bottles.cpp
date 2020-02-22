/**
 * Problem: Max profit in selling wine bottles from edge points.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Bottom up
// Two variable states: beginning position and ending position.
int maxProfit(int* arr, int low, int high,int year,int dp[][100]){
    if(low>high){
        return 0;
    }
    
    if(dp[low][high]!=-1) return dp[low][high];
    
    
    
    dp[low][high] = max((arr[low]*year + maxProfit(arr,low+1,high,year+1, dp)),(arr[high]*year + maxProfit(arr,low,high-1, year+1, dp)));
    return dp[low][high];
} 

// Top down approach.
// Hints taken from bottom up to get this solution.
int maxProfitDP(int* arr,int len_arr, int dp[][100]){
    // Starting from last year.
    int year = len_arr;
    
    // Initializing keeping in mind that i have only 1 wine bottle on the table.
    // When only 1 wine bottle is left, that means last year.
    // Therefore, year = len_arr
    for(int i=0;i<len_arr;i++){
        dp[i][i] = year*arr[i];
    }
    
    --year;
    
    // Main Operation.
    // Here computation is done diagonally i.e. dp table filled diagonally.
    // Therefore not going the normal 2 nested loop way because that fills elements row wise
    // or column wise
    for(int len = 2;len<=len_arr;len++){
        // start is row. Always starts from 0.
        int start = 0;
        int end = len_arr - len;
        
        while(start<=end){
            int end_window = start + len -1;
            dp[start][end_window] = max((arr[start]*year + dp[start+1][end_window]),(arr[end_window]*year + dp[start][end_window-1]));
            start++;
        }
        --year;
        
    }
    
    
    
    // Printing the profit table.
    for(int i=0;i<len_arr;i++){
        for(int j=0;j<len_arr;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[0][len_arr-1];
}



void resetDP(int dp[][100]){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            
        dp[i][j] = -1;
        }
    }
}


 
int main() {
    int arr[] ={2,3,5,1,4};
    int dp[100][100];
    resetDP(dp);
    int ans = maxProfitDP(arr,5, dp);
    cout<<ans<<endl;
    
    // resetDP(dp);
    // ans = minimumStepsDP(num,dp);
    // cout<<ans;
    
	return 0;
}