/**
 * Problem: 1->a, 26->z. Corresponding alphabets string print.
 */
#include<bits/stdc++.h>
using namespace std;

void correspondingChar(string s,string alphabets, int index,string formed){
    if(index==s.length()){
        cout<<formed<<endl;
        return;
    }
    
    // Recursive
    // 1. Taking current character only and converting to int.
    int c = s[index] - '0';
    // cout<<c;
    formed += alphabets[c];
    correspondingChar(s,alphabets,index+1,formed);
    
    //2. Taking current character and the next character.
    // Backtracking, removing current character and checking if 2 characters at a time
    // can be considered.
    formed.pop_back();
    if(index<s.length()-1){
        int c1 = (s[index] - '0')*10;
        int c2 = s[index+1] - '0';
        if(c1+c2<=26){
            formed += alphabets[c1+c2];
            correspondingChar(s,alphabets,index+2,formed);
        }
    }
}


int main() {
    string alphabets("0abcdefghijklmnopqrstuvwxyz");
    string s;
    string formed="";
    cin>>s;
    correspondingChar(s,alphabets,0,formed);
	return 0;
}