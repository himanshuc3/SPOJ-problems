/**
 * Problem: Subsquences of a string.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void generateSubsequence(string s, int num){
    if(num==0){
        cout<<"null, ";
        return;
    }
    int j=0;
    
    while(num!=0){
        if(num&1){
           cout<<s[j]; 
        }
        num = num>>1;
        j++;
    }
    cout<<", ";
}

void printSubsequences(string s, int n){
    
    // 2^n-1.
    // "-" has higher precedence than <<.
    // So, use brackets.
    int numberOfSubsequences = (1<<n) - 1;
    
    for(int i=0;i<=numberOfSubsequences;i++){
        
        generateSubsequence(s,i);
    }
}

int main() {
   string s;
   cin>>s;
   
   int len = s.length();
   
   printSubsequences(s,len);
    
    
	return 0;
}