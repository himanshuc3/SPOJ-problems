/**
 * Problem: Book allocation - google interview problem.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValidConfig(ll books[], ll n, ll k, ll ans){
    ll students = 1;
    ll current_pages = 0;
    
    for(ll i=0;i<n;i++){
        if(current_pages+books[i]<=ans){
            current_pages+=books[i];
        }else{
            students++;
            current_pages=books[i];
            if(students>k){
                return false;
            }
        }
    }
    
    return true;
}

ll binarySearchOnBooks(ll books[], ll n,ll k){
    ll total_pages=0;
    for(int i=0;i<n;i++){
        total_pages += books[i];
    }
    ll s=books[n-1],e= total_pages;
    ll finalAns;
    while(s<=e){
        ll mid = (s + e )/2;
        if(isValidConfig(books,n,k,mid)){
            // true - search in left part
            e=mid-1;
            finalAns = mid;
            
        }else{
            // false - search in right part
            s = mid+1;
        }
    }
    return finalAns;
}
 
int main() {
    // n = number of books
    // k = number of students
    ll n,k;
    cin>>n>>k;
    
    
    ll books[100005];
    
    for(int i=0;i<n;i++){
        cin>>books[i];
    }
    
    int min = binarySearchOnBooks(books, n, k);
    cout<<min;
    
    
	return 0;
}