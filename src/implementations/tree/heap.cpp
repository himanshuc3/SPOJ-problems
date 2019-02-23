/**
 * Problem: Min heap implementation
 *          Also doing heap sort.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char, node*>

class MinHeap{
    vector<int> v;
    
    void heapify(int index){
        int leftChild = 2*index;
        int rightChild = 2*index + 1;
        int size = v.size()-1;
        int minIndex = index;
        if(leftChild<=size&&v[leftChild]<v[index]){
            minIndex = leftChild;
        }
        if(rightChild<=size&&v[rightChild]<v[minIndex]){
            minIndex = rightChild;
        }
        if(minIndex != index){
            swap(v[index],v[minIndex]);
            heapify(minIndex);
        }
    }
    
    public:
        MinHeap(){
            // starts from index 1
            v.push_back(-1);
        }
        void push(int data){
            v.push_back(data);
            int index= v.size()-1;
            int parent = index/2;
            
            // don't need to calculate parent of index = 1;
            while(index>1&&v[index]<v[parent]){
                swap(v[index],v[parent]);
                index = parent;
                parent = index/2;
            }
        }
        
        // get min element/root element
        int getMinElement(){
            if(v.size()>1){
            return v[1];
            }
            return -1;
        }
        
        // deletes min element
        void pop(){
            int last = v.size()-1;
            swap(v[1],v[last]);
            v.pop_back();
            heapify(1);
        }
        
        bool empty(){
            return !(v.size()-1);
        }
};

int main() {
    int a[] = {1,4,3,2,6,0,10,12};
    int n = sizeof(a)/sizeof(a[0]);
    MinHeap h;
    for(int i=0;i<n;i++){
        h.push(a[i]);
    }
    
    while(!h.empty()){
        cout<<h.getMinElement()<<"-";
        h.pop();
    }
    
    
	return 0;
}