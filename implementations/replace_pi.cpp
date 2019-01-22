/**
 * Takeaway: Don't set string using s[k] = 'a' if k > s.length(). 
 * Instead do s.push_back('a').
 * 
 * Problem: Replace all occurences of pi with 3.14
 */
#include<bits/stdc++.h>
using namespace std;

int numberOfPi(string s,int len){
    int count = 0;
    for(int i=0;i<len;i++){
        if(i<len-1&&s[i]=='p'&&s[i+1]=='i'){
            count++;
            i++;
        }
    }
    return count;
}


int main() {
    int n=0;
    string s;
    cin>>n;
    cin>>ws;
    
    while(n--){
        cin>>s;
        int len = s.length();
        int count = numberOfPi(s,len);
        int afterLength = len + count*2;
        
        
        for(int k=len;k<afterLength;k++){
            s.push_back('q');
        }
        for(int i=len-1,j=afterLength-1;i>=0;){
            if(i>0&&s[i]=='i'&&s[i-1]=='p'){
                s[j] = '4';
                s[j-1] = '1';
                s[j-2] = '.';
                s[j-3] = '3';
                j-=4;
                i-=2;
            }else{
                s[j] = s[i];
                j--;
                i--;
            }
        }
        cout<<s<<endl;
    }
	return 0;
}