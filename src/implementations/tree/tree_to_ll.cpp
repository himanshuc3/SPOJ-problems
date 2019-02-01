/**
 * Problem: Convert tree 2 Linked list.
 * Alias: Flattening the tree.
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


class LinkedList{
    public:
     node* head;
     node* tail;
};
    
LinkedList tree2LL(node* root){
    LinkedList l;
    // Base Case - Only hits when tree is empty
    if(root==NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    // Leaf Node - Base Case
    if(root->left==NULL && root->right == NULL){
        l.head = root;
        l.tail = root; 
    }else if(root->left!=NULL && root->right==NULL){
        // Make a linked list from leftSubTree
        LinkedList leftLL = tree2LL(root->left);
        // We are only using right pointers for representing linked list.
        // This is a stylistic choice.
        // In the below statement, tail pointer of the leftLL connects to root via right pointer.
        leftLL.tail->right = root;
        
        // We make the list using leftLL and root.
        l.head = leftLL.head;
        l.tail = root;
    }else if(root->left==NULL && root->right!=NULL){
        // Make a linked list from rightSubTree
        LinkedList rightLL = tree2LL(root->right);
        // We are only using right pointers for representing linked list.
        // Closing off the linked list.
        root->right = rightLL.head;
        
        // We make the list using leftLL and root.
        l.head = root;
        l.tail = rightLL.tail;
    }else{
        
        // Fetching left and right subtrees.
        // Merging the leftLL, root and rightLL.
        LinkedList rightLL = tree2LL(root->right);
        LinkedList leftLL = tree2LL(root->left);
        
        leftLL.tail->right = root;
        root->right = rightLL.head;
        
        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}
 
int main() {
    node* root = NULL;
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    root = balancedBSTFromSortedArray(arr,0,9);
    LinkedList l = tree2LL(root);
    node* temp = l.head;
    
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    
	return 0;
}