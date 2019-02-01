/**
 * Problem: BFS traversal.
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
   

// BFS traversal with each level separated
// So works like level order traversal

void BFSTraversal(node* root){
    
    if(root==NULL){
        return;
    }
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* currentNode = q.front();
        
        if(currentNode==NULL){
            // Check for whether there are any more nodes after NULL.
            // If this is not handled, NULL would be pushed indefinitely.
            if(q.size()!=1){
                q.push(NULL);
                cout<<endl;
            }
            
        }else{
            cout<<currentNode->data<<" ";
        if(currentNode->left){
            q.push(currentNode->left);
        }
        
        if(currentNode->right){
            q.push(currentNode->right);
        }
        }
        
        q.pop();
        
    }
    
    
}
    
 
int main() {
    node* root = NULL;
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    root = balancedBSTFromSortedArray(arr,0,9);
    BFSTraversal(root);
    
	return 0;
}