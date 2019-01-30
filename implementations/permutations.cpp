/**
 * Problem: Permutations of a string.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Recursive
void permutations(char* in,int i){
    // Base case
    if(in[i]=='\0'){
        cout<<in<<endl;
        return;
    }
    
    // Replace in[i] with in[j] and keep on form permutations
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permutations(in, i+1);
        swap(in[i],in[j]);
    }
}

int main() {
    char in[] = "abc";
    permutations(in,0);
    
    
    
    
	return 0;
}