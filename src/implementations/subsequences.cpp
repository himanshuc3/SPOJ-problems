/**
 * Problem: Printing all subsequences of a string of length <=20.
 * Solution: Using Recursion. 
 * Key: Using map for the special case of repeating characters.
 *
 */




#include<bits/stdc++.h>
using namespace std;

vector<string> vec;
map<string, int> m;

void printSubsequences(string s, unsigned int currentPos,string formed){
    //Past length of string
    if(currentPos==s.length()){
        if(!m.count(formed)){
            vec.push_back(formed);
            m.insert(pair<string,int>(formed,1));
        }
        return;
    }
    
    //1.Current char included
    formed += s[currentPos];
    printSubsequences(s,currentPos+1,formed);
    
    //2.Current character excluded
    formed.pop_back(); //Back-Track
    printSubsequences(s,currentPos+1,formed);
}

int main() {
    int n;
    cin>>n;
    string s, empty="";
    cin>>ws;
    while(n--){
        cin>>s;
        sort(s.begin(), s.end());
        printSubsequences(s, 0, empty);
        sort(vec.begin(),vec.end());
        for(vector<string>::iterator it=vec.begin(); it!=vec.end(); ++it){
            cout<<*it<<endl;
        }
    }
    
	return 0;
}