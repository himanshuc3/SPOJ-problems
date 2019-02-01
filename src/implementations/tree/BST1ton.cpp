/**
 * Problem: Form BSTs given nodes from 1 to n.
 * A good standard recursive problem.
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

void preOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<"->";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

node* newNode(int data) { 
    node *temp =  new node(data);
    temp->left = temp->right = NULL; 
    return temp; 
} 

// Bottom Up Approach of Recursion.
// We are given 1,2....n nodes.
// Find the number of BST combinations possible with those values.
// Formula: Catalan Number = (2n)!/(n+1)!n!
// Number of BT combinations = (Catalan Number)*n!
vector<node*> countBST(int low, int high){
    vector<node*> list;
    
    // Base Case
    // Subtree is empty therefore add NULL and return
    if(low>high){
        list.push_back(NULL);
        return list;
    }
    
    // Recursive Case
    // Going from node low to high setting the root node as currentValue
    for(int currentValue=low;currentValue<=high;currentValue++){
        
        // Example: If currentValue = 3 and high = n = 7, then:
        // leftSubTree consists of (1,2) and rightSubTree consists of (4,5,6,7)
        // where 3 is the root node.
        vector<node*> leftSubTree = countBST(low,currentValue-1);
        vector<node*> rightSubTree = countBST(currentValue+1,high);
        
        // Connecting different combinations of leftSubTree and rightSubTree to root node.
        
        // Taking 1 leftSubTree root node at a time.
        for (int j = 0; j < leftSubTree.size(); j++) 
        { 
            node* left = leftSubTree[j]; 
            
            // Taking 1 rightSubTree root node at a time.
            for (int k = 0; k < rightSubTree.size(); k++) 
            { 
                node * right = rightSubTree[k];
                
                // Forming a new root node with currentValue
                node * node = newNode(currentValue);// making value i as root 
                node->left = left;              // connect left subtree 
                node->right = right;            // connect right subtree 
                // Adding this particular combination of leftSubTree and rightSubTree onto list.
                list.push_back(node);           // add this tree to list 
            } 
        } 
        // end for
    }
    return list;
}
int main() {
     vector<node*> list = countBST(1,5);
    
    for(int i=0;i<list.size();i++){
        preOrderPrint(list[i]);
        separator();
    }
    
	return 0;
}