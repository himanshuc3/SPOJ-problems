/**
 * Problem: Unique Permutations of a string (works even if characters repeated).
 * 
 */
#include<bits/stdc++.h>
using namespace std;


// Recursive
void permutations(char* in,int i,set<string> &s){
    // Base case
    if(in[i]=='\0'){
        string temp = in;
        s.insert(in);
        return;
    }
    
    // Replace in[i] with in[j] and keep on form permutations
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permutations(in, i+1,s);
        swap(in[i],in[j]);
    }
}

int main() {
    char in[10];
    cin>>in;
    
    // For storing unique permutations.
    // By default, set also sorts items in it.
    set<string> s;
    
    permutations(in,0,s);
    
    for(auto i:s){
        cout<<i<<endl;
    }
    
    
	return 0;
}