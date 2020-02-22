#include<bits/stdc++.h>
using namespace std;

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

	int a,b ;
	cout<<"Enter base: ";
	cin>>a;
	cout<<"\nEnter power: ";
	cin>>b;

	cout<<a<<" to the power "<<b<<" is: "<<fast_exponentiation(a,b);


	return 0;
}