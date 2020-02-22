/**
 * Problem: Build BST from sorted array.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// node class 
// Ideally, other methods should be either in this class
// or tree class using node class.
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
};

void preOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<"->";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

node* balancedBSTFromSortedArray(int arr[],int low, int high){
    // Base Case
    if(low>high){
        return NULL;
    }
    
    // Recursive Case
    // For preventing going above limit of int (overflow).
    // Index of current value
    int mid = low + (high-low)/2;
    node* leftSubTree = balancedBSTFromSortedArray(arr,low,mid-1);
    node* rightSubTree = balancedBSTFromSortedArray(arr,mid+1,high);
    
    node* n = new node(arr[mid]);
    n->left = leftSubTree;
    n->right = rightSubTree;
    
    return n;
}



int main() {
    node* root = NULL;
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    root = balancedBSTFromSortedArray(arr,0,9);
    preOrderPrint(root);
    
	return 0;
}