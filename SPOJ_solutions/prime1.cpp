#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX 100001

bool isPrime[MAX];
void primeSieve(){
    for(long int i=0;i<MAX;i++)isPrime[i] = false;
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    for(long int i=3;i<MAX;i+=2)isPrime[i] = true;
    
    //1. Iterate over odd numbers
    int root_max = MAX>>1;
    for(long int i=3;i<MAX;i+=2){
        
        if(isPrime[i]){
            for(long int j=i*i;j<MAX;j+=2*i)isPrime[j] = false;
        }
    }
    
}

void printPrimes(long int l, long int r){
    int diff= r-l;
    bool primes[diff+1];
    memset(primes, true, sizeof(primes));
    for(long int i=2;i*i<=r;i++){
        if(isPrime[i]){
            for(long int k=l;k<=r;k++){
                if(k%i==0 && k!=i)primes[k-l]=false;
            }
        }
    }
    if(l==1)primes[0]=false;
    for(int i=0;i<=diff;i++){
        if(primes[i]){
            cout<<i+l<<endl;
        }
    }
}

int main() {
	int t;
	long int m,n;
	cin>>t;
	primeSieve();
	while(t--){
	    cin>>m>>n;
	    printPrimes(m,n);
	    cout<<endl;
	    
	}
	
}
