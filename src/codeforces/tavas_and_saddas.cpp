/**
 * Problem: B. tavas and saddas
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void luckyNumberPosition(string n){
    int len = n.length();
    ll numbers = (1<<len) - 2;
    
    // Iterate over the number from units place
    for(int i=len-1,pos=0;i>=0;i--,pos++){
        // If current number is 7, we could virtually switch it with 4 and 
        // add no. of numbers = 2^(position of current bit -1)
        if(n[i]=='7')
        numbers += (1<<pos);
    }
    cout<<numbers+1;
}




int main() {
    string n;
    cin>>n;
    
    luckyNumberPosition(n);

   
    
    
	return 0;
}