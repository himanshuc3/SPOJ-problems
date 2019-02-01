/**
 * Problem: Diameter of a tree (only edges counted).
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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    
    return max(height(root->left),height(root->right))+1;
}



node* newNode(int data) { 
    node *temp =  new node(data);
    temp->left = temp->right = NULL; 
    return temp; 
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



class MyPair{
    public: 
        int height;
        int diameter;
};
 
// Top-down approach.
// O(n^2) time complexity.
// Diameter doesn't include singular nodes, it counts number of edges between nodes.
int diameterSlow(node* root){
    if(root==NULL){
        return 0;
    }
    
    // h1 is computed in O(n)
    // Done at each node, so O(n^2) because of this height computation step == BOTTLENECK.
    int h1 = height(root->left) + height(root->right);
    int left_diameter = diameterSlow(root->left);
    int right_diameter = diameterSlow(root->right);
    return max(h1,max(left_diameter,right_diameter));
} 

// Bottom up approach
// O(n) time complexity

MyPair diameterFast(node* root){
    MyPair p;
    // Base Case
    if(root==NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    
    // Recursive case
    MyPair left_sub_tree = diameterFast(root->left);
    MyPair right_sub_tree = diameterFast(root->right);
    
    p.height = max(left_sub_tree.height,right_sub_tree.height)+1;
    p.diameter = max(left_sub_tree.height+right_sub_tree.height,max(right_sub_tree.diameter,left_sub_tree.diameter));
    return p;
    
}
 
int main() {
    node* root = NULL;
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    root = balancedBSTFromSortedArray(arr,0,9);
    int d = diameterSlow(root);
    cout<<d<<endl;
    MyPair d2= diameterFast(root);
    cout<<d2.diameter;
	return 0;
}