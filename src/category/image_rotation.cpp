#include<bits/stdc++.h>
using namespace std;



void print(int** a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


int main(){
    int n;
    cin>>n;
    int** a;
    a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"BEFORE ROTATION:\n";
    print(a,n);
    
    
    int temp;
    
    // 90degree left rotation
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            temp = a[i][j];
            //top left corner
            a[i][j] = a[i][n-j-1];
            // top right corner
            a[i][n-j-1] = a[n-i-1][n-j-1];
            //bottom right corner
            a[n-1-i][n-1-j] = a[n-i-1][j];
            //bottom left corner
            a[n-1-i][j] = temp;
        }
    }
    
    cout<<"AFTER ROTATION:\n";
    print(a,n);
    
    
}