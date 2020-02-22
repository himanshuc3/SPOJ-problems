/******************************************************************************

Problem Statement: Perform either of 2 queries: 1. Print sum from [L,R].
                                                2. Update Value at ith index.
                    

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int query(int *blocks, int *arr, int L,int R, int rn){
    
    int ans = 0;
    
    //left part
    while(L<R && L!=0 && L%rn!=0){
        ans += arr[L];
        L++;
    }
    
    //middle part
    while(L+rn<=R){
        int block_id = L/rn;
        ans += blocks[block_id];
        L += rn;
    }
    
    
    //right part
    while(L<=R){
        ans += arr[L];
        L++;
    }
    return ans;
}

void update(int *blocks,int *arr, int i, int val,int rn){
    int block_id = i/rn;
    blocks[block_id] = val - arr[i];
    arr[i] = val;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int rn = sqrt(n);
    
    int block_id = -1;
    int *blocks = new int[rn+1]{0};
    for(int i=0;i<n;i++){
        
        if(i%rn==0){
            block_id++;
        }
        blocks[block_id] += arr[i];
        
    }

    cout<<query(blocks,arr,2,8,rn);
    update(blocks,arr,2,15,rn);
    cout<<query(blocks,arr,2,8,rn);
    return 0;
}
