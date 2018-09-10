#include<bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int s, int e,int data){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(data==arr[mid]){
        return mid;
    }else if(data<arr[mid]){
        binarySearch(arr,s,mid-1,data);
    }else{
        binarySearch(arr,mid+1,e,data);
    }
}

int firstOccur(int* arr, int n, int data){
    int s = 0, e = n-1;
    int mid,ans = -1;
    while(s<=e){
        mid= (s+e)/2;
        if(data==arr[mid]){
            ans = mid;
            e = mid-1;
        }else if(data<arr[mid]){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}

int searchInRotatedArray(int* arr, int s, int e, int data){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(arr[mid]==data){
        return mid;
    }else if(arr[s]<arr[mid]){
        //Means left part is sorted i.e.
        // mid lies in 1st line
        if(data>=arr[s]&&data<arr[mid]){
            return searchInRotatedArray(arr,s,mid-1,data);
        }else{
            return searchInRotatedArray(arr,mid+1,e,data);
        }
        
    }
    //Means right part is sorted i.e.
    // mid lies in 2nd line
    if(data>arr[mid]&&data<=arr[e]){
            return searchInRotatedArray(arr,mid+1,e,data);
        }else{
            return searchInRotatedArray(arr,s,mid-1,data);
        }
    
}

int pivotElement(int* arr,int s,int e){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(arr[mid-1]>arr[mid]){
        return mid-1;
    }
    if(arr[mid]>arr[mid+1]){
        return mid;
    }
    if(arr[s]<=arr[mid]){
        return pivotElement(arr, mid+1,e);
    }else{
        return pivotElement(arr,s,mid-1);
    }
}

void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
    int arr[8] = {5,6,7,8,9,3,4};
    // cout<<firstOccur(arr,8,8);
    // cout<<searchInRotatedArray(arr,0,6,6);
    cout<<pivotElement(arr,0,6);
    return 0;
}