/**
 * Problem: Check if a binary tree is bst or not.
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

void separator(){
    cout<<endl<<"==================="<<endl;
    cout<<"==================="<<endl;
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

// Simple Way: printInorder traversal and check if it is sorted.
// 1 defect: doesn't work for duplicate elements
// This method is therefore preferred.
// Top down approach. Bottom up approach would return min and max from bottom whereas
// in top-down we check from root itself.
bool isBST(node* root, int min, int max){
    if(root==NULL){
        return true;
    }
    
    if(root->data>min && root->data<=max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
        return true;
    }
    return false;
}

int main() {
    node* root = NULL;
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    root = balancedBSTFromSortedArray(arr,0,9);
    separator();
    bool isB = isBST(root,INT_MIN, INT_MAX);
    (isB==true)?cout<<"BST":cout<<"Get out of here!";
    
	return 0;
}