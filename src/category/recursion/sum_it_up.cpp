/**
 * Problem: Print all subsets having sum = t and unique.
 *
 */




#include<bits/stdc++.h>
using namespace std;


// Storing all subsets with sum = t ( includes repeating subsets).
vector<vector<int> > v;

void sumItUp(vector<int> arr, int index,int t,vector<int> temp){
    //Past length of string
    if(index==arr.size()){
        int sum = 0;
        for(int i=0;i<temp.size();i++){
            sum += temp[i];
        }
        if(sum==t){
            v.push_back(temp);
        }
        return;
    }
    
    //1.Current char included
    temp.push_back(arr[index]);
    sumItUp(arr,index+1,t,temp);
    
    //2.Current character excluded
    temp.pop_back(); //Back-Track
    sumItUp(arr,index+1,t,temp);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    vector<int> temp;
    sumItUp(arr,0,t,temp);
    
    // for creating unique subsets
    set<vector<int> > s;
    
    for(auto i:v){
        sort(i.begin(),i.end());
        s.insert(i);
    }
    
    //printing subsets with sum = t.
    for(auto i:s){
        for(auto num:i){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}