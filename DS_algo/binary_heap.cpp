#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int* harr; // heap array implementation
    int capacity; // Max size of array
    int heap_size; // Elements in heap array;
    public:
    MinHeap(int capacity){
        this->capacity = capacity;
        heap_size= 0;
        harr = new int[capacity];
    }
    
    int getParent(int i){
        return (i-1)/2;
    }
    int getLeftChild(int i){
        return 2*i + 1;
    }
    int getRightChild(int i){
        return 2*i + 2;
    }
    
    void insertNode(int k){
        if(heap_size==capacity){
            cout<<"Overflow: could not insert key/n";
            return;
        }
        
        // insert key at end of full binary tree
        harr[heap_size++] = k;
        int i= heap_size - 1;
        while(i!=0&&harr[getParent(i)]>harr[i]){
            swap(harr[getParent(i)],harr[i]);
            i = getParent(i);
        }
    }
    
    int deleteRootNode(){
        if(heap_size==0){
            return INT_MAX;
        }else if(heap_size==1){
            heap_size = 0;
            return harr[0];
        }
        
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
        return root;
    }
    
    void MinHeapify(int i){
        int left = getLeftChild(i);
        int right = getRightChild(i);
        int smallest = i;
        if(left<heap_size&&harr[left]<harr[smallest])
            smallest = left;
        if(right<heap_size&&harr[right]<harr[smallest])
            smallest = right;
        
        if(smallest!=i){
            swap(harr[smallest],harr[i]);
            MinHeapify(i);
        }
    }
    
    void printHeap(){
        for(int i=0;i<heap_size;i++){
            cout<<harr[i]<<" ";
        }
    }
    
    
    
};

int main(){
   MinHeap h(10);
   h.insertNode(15);
   h.insertNode(10);
   h.insertNode(20);
   h.insertNode(4);
   h.insertNode(7);
   h.insertNode(17);
   h.insertNode(2);
   h.deleteRootNode();
   h.printHeap();
   return 0;

}