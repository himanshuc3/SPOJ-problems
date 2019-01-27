#include<bits/stdc++.h>
using namespace std;

void printPossibleCombinations(string n,string table[], unsigned int curr,string formed){
    if(curr==n.length()){
        cout<<formed<<endl;
        return;
    }
    
    //Recursive case
    int index = int(n[curr]-'0');
    for(unsigned int i=0;i<table[index].length();i++){
        formed+=table[index][i];
        printPossibleCombinations(n,table,curr+1,formed);
        formed.pop_back();
    }
}
int main() {
    string s;
    cin>>s;
    string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
    string formed="";
    printPossibleCombinations(s,table,0,formed);
	return 0;
}

