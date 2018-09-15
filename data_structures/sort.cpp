#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int* arr, int n){
    int k = n-1;
    while(k--){
        for(int j=0;j<=k;j++){
            if(arr[j+1]<arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
        
}

void selectionSort(int* arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }else{
                break;
            }
        }
    }
}

void insertionSort(int* arr, int n){
    int min;
    int index;
    for(int i=0;i<n;i++){
        min = arr[i];
        index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}

void waveSort(int* arr, int n){
    for(int i=0;i<n;i+=2){
        // Check for left element
        if(i>0&&arr[i-1]>arr[i]){
            swap(arr[i],arr[i-1]);
        }
        //Check for right element
        if(i<n-1&&arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
}

void countSort(int* arr, int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max)max=arr[i];
    }
    int countArr[max+1] = {0};
    for(int i=0;i<n;i++){
        countArr[arr[i]] +=1;
    }
    int j=0;
    for(int i=0;i<=max;i++){
        while(countArr[i]!=0){
            arr[j] = i;
            countArr[i]--;
            j++;
        }
    }
}

void merge(int* arr, int s, int e){
    int mid = (s+e)/2;
    int i= s;
    int j = mid+1;
    int k=s;
    
    int temp[100];
    
    while(i<=mid&&j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    
    //We need to copy all elements to original array
    for(int z=s;z<=e;z++){
        arr[z] = temp[z];
    }
    
}

void mergeSort(int* arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    //2. Recursively divide the arrays
    mergeSort(arr,s,mid-1);
    mergeSort(arr,mid+1,e);
    
    //merge
    merge(arr,s,e);
}

void printArray(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
}

void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
    int arr[5] = {5,2,4,1,3};
    // bubbleSort(arr,5);
    // selectionSort(arr,5);
    // insertionSort(arr,5);
    // waveSort(arr, 5);
    countSort(arr,5);
    printArray(arr,5);
    return 0;
}