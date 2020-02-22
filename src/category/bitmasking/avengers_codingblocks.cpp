#include<bits/stdc++.h>
using namespace std;

#define ll long long

int fast_exponentiation(int a, int b){

	int ans = 1,
		current_number = a;

	while(b>0){
		if(b&1){
			ans *= current_number;
		}
		
		b = b>>1;
		current_number = current_number*current_number;
	}

	return ans;
}

int main(){
    // no. of test cases
	ll t;
	cin>>t;
	
	ll primes[] = {2,3,5,7,11,13,17,19};
	
	
	while(t--){
	    ll n;
	    cin>>n;
	    
	    // no. of subsets for prime
	    ll subsets = 1<<8 - 1;
	    ll ans = 0;
	    
	    for(ll i=1; i<=subsets;i++){
	        ll denom = 1ll;
	        ll setBits = __builtin_popcount(i);
	        
	        for(ll j=0;j<=7;j++){
	            if(i&(1<<j)){
	                denom *= primes[j];;
	            }
	        }
	        if(setBits&1){
	            ans += n/denom;
	        }else {
	            ans -= n/denom;
	        }
	    }
	    cout<<ans<<endl;
	}

	return 0;
}