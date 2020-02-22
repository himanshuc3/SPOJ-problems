/**
 * Problem: Max area using stack of a histogram in O(n) time.
 * Tip: Simple but not easy. A cool problem.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int maxArea(int arr[], int n){
    stack<int> s;
    s.push(0);
    int max_area = INT_MIN;
    int prevTop;
    for(int i=1;i<n;i++){
        
        if(arr[i]>arr[s.top()]){
            s.push(i);
        }else{
            while(!s.empty() && arr[i]<arr[s.top()]){
            prevTop = s.top();
            s.pop();
            
            if(s.empty()){
                max_area = max(max_area,arr[prevTop]*i);
            }else{
                max_area = max(max_area, arr[prevTop]*(i-s.top()-1));
            }
            }
            s.push(i);
        }
        
    }
    return max_area;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<maxArea(arr,n);
    
	return 0;
}