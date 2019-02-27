/**
 * Problem: Min k elements on a running stream of numbers.
 *          Not working correctly. TO-DO
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void showpq(priority_queue <int, vector<int>, greater<int> > gq,int k) 
{ 
    priority_queue<int, vector<int>, greater<int>> g = gq; 
    int i=0;
    while (!g.empty()) 
    {   if(i==k)break;
        i++;
        cout<<g.top()<<"-"; 
        g.pop(); 
    } 
    cout << '\n'; 
} 


void minKElements(int k){
    priority_queue<int, vector<int>, greater<int> > pq;
    int data;
    // if true query top k elements,
    // else skip
    bool query;
    int numberOfElements = 0;
    cin>>data;
    while(data!=-1){
        if(numberOfElements<k){
            pq.push(data);
        }else{
            if(pq.top()<data){
                pq.pop();
                pq.push(data);
            }
        }
        cin>>query;
        if(query){
            showpq(pq,k);
        }
        
        cin>>data;
    }
}

int main() {
    int k;
    cin>>k;
    minKElements(k);
    
    
	return 0;
}