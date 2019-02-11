/**
 *  
 * Problem: Tower of hanoi. Classical Recursion problem.
 *
 * 
 */
#include<bits/stdc++.h>
using namespace std;


void towerOfHanoi(char source, char mediator, char destination, int n){
    if(n==0){
        return;
    }
    
    //move n-1 disks to mediator
    towerOfHanoi(source,destination,mediator,n-1);
    //move disk
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<"."<<endl;
    //move n-1 disks from mediator to destination
    towerOfHanoi(mediator,source,destination,n-1);
    
}

int main() {
    int n;
    cin>>n;
    
    towerOfHanoi('a','b','c',n);
    
	return 0;
}