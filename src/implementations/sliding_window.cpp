/**
 * Problem: Find largest number in window of size k for every continuous window of size k.
 * Input: array of integers, k - window length
 * 
 * 
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,i;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    deque<int> Q(k);
    //Pre-processing first k elements
    for(i=0;i<k;i++){
        
        while(!Q.empty()&&arr[i]>=arr[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<arr[Q.front()]<<"--";
    
    for(;i<n;i++){
        //Displaying largest in current window
        
        
        //1. Remove elements not part of current window (contraction)
        while(!Q.empty()&&(Q.front()<=i-k)){
            Q.pop_front();
        }
        
        //2. Remove elements from back which are less than current element
        while(!Q.empty()&&arr[i]>=arr[Q.back()]){
            Q.pop_back();
        }
        
        //3. Expansion, push latest elements anyways
        Q.push_back(i);
        cout<<arr[Q.front()]<<"--";
    }
    
    
    
}