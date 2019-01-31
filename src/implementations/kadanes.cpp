#include<bits/stdc++.h>
using namespace std;

void maxSumKadanesAlgo(int arr[], int n){
    int currentSum = 0;
    int maxSum = 0;
    
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        
        if(currentSum<0)currentSum=0;
        if(currentSum>maxSum)maxSum=currentSum;
    }
    cout<<maxSum<<endl;
    
}

int main(){
    int n,d;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    maxSumKadanesAlgo(arr,n);
    
}