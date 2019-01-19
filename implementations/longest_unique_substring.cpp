/**
 * Problem: Find longest unique substring.
 * Input: string
 * output: length
 * 
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>ws>>s;
    
    unsigned int len = s.length();
    int current_len = 1;
    int max_len = 1;
    
    //Ascii standard length
    //Storing latest index of character
    int visited[256];
    for(int i=0;i<256;i++){
        visited[i] = -1;
    }
    
    visited[int(s[0])] = 0;
    
    for(int i=1;i<len;i++){
        //Storing last occurance of current character
        int last_occur = visited[int(s[i])];
        
        //Never occured before or occured outside current length
        //Expansion
        if(last_occur==-1||i-current_len>last_occur){
            current_len++;
        }else{
            //Expansion + contraction
            current_len = i-last_occur;
        }
        visited[int(s[i])] = i;
        if(current_len>max_len){
                max_len = current_len;
        }
    }
    cout<<max_len;
    
    
    
}