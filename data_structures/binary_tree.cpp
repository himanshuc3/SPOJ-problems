#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node* left;
    node* right;
    node(int data){
    d = data;
    left = NULL;
    right = NULL;
  }
};

class Pair{
    public:
        int height;
        int diameter;
};

class HBPair{
    public:
        int height;
        bool balance;
};

node* buildTree(){
        int data;
        cin>>data;
        if(data==-1){
            return NULL;
        }
        node* new_node = new node(data);
        new_node->left = buildTree();
        new_node->right = buildTree();
        return new_node;
}
    
int height(node* root){
        if(root==NULL){
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int h = max(h1,h2)+1;
        return h;
}

void printKthLevel(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->d<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}

void levelOrderPrint(node* root){
    int h = height(root);
    
    for(int i=1;i<=h;i++){
        printKthLevel(root, i);
        cout<<endl;
    }
}

void BFS(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
        cout<<f->d<<" ";
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
        q.pop();
        }
    }
}
    
void preOrderPrint(node* curr){
        if(curr==NULL){
            return;
        }
        cout<<curr->d<<" ";
        preOrderPrint(curr->left);
        preOrderPrint(curr->right);
}
    
void postOrderPrint(node* curr){
        if(curr==NULL){
            return;
        }
        postOrderPrint(curr->left);
        postOrderPrint(curr->right);
        cout<<curr->d<<" ";
}
void inorderPrint(node* curr){
        if(curr==NULL){
            return;
        }
        inorderPrint(curr->left);
        cout<<curr->d<<" ";
        inorderPrint(curr->right);
}

int count(node* root){
    if(root==NULL){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

HBPair isHeightBalanced(node* root){
    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recursive case
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    
    p.height = max(left.height,right.height) + 1;
    
    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance = true;
    }else{
        p.balance = false;
    }
}

int replaceSum(node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->d;
    }
    //Recursive part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);
    int temp = root->d;
    root->d = leftSum + rightSum;
    return temp + root->d;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}

Pair diameterFast(node* root){
    Pair p;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = diameterFast(root->left);
    Pair right = diameterFast(root->right);
    
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter,right.diameter));
    return p;
    
}

node* buildTreeFromArray(int* a, int s, int e){
    //Base
    if(s>e){
        return NULL;
    }
    //Recursive
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1, e);
    
    return root;
}

node* createTreeFromTrav(int*in,int*pre,int s, int e){
    static int i=0;
    //Base case
    if(s>e){
        return NULL;
    }
    //Rec case
    node* root = new node(pre[i]);
    
    //searching for pre[i] in in[]
    int index=-1;
    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(in, pre, s, index-1);
    root->right = createTreeFromTrav(in,pre,index+1,e);
    return root;
    
}

int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->d;
}
    

int main(){
    node* root=NULL;
    // root = buildTree();
    // preOrderPrint(root);
    // cout<<endl;
    // postOrderPrint(root);
    // cout<<endl;
    // inorderPrint(root);
    // cout<<endl;
    // printKthLevel(root,1);
    // cout<<endl;
    // levelOrderPrint(root);
    // cout<<endl;
    // BFS(root);
    // cout<<endl;
    // replaceSum(root);
    // cout<<endl;
    // BFS(root);
    // if(isHeightBalanced(root).balance){
    //     cout<<"Balanced";
    // }else{
    //     cout<<"Not a balanced tree;"
    // }
    // int a[] = {1,2,3,4,5,6,7};
    // int n= 7;
    // root = buildTreeFromArray(a, 0, n-1);
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(in)/sizeof(int);
    root = createTreeFromTrav(in,pre,0,n-1);
    BFS(root);
    return 0;
}

