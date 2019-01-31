#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node {
    public:
    int d;
    node* next;
    node(int d){
        this->d = d;
        next=NULL;
    }
};

class LinkedList{
    private:
    node* head;
    node* tail;
    
    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtHead(int data){
        node* n = new node(data);
        n->next = this->head;
        if(this->head==NULL){
            this->tail = n;
        }
        this->head = n;
    }
    
    bool detectCycle(){
        node* slow = this->head;
        node* fast = this->head;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
    
    void loopRemoval(){
        node* slow = this->head;
        node* fast = this->head;
        while(fast!=slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = this->head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        while(fast->next!=slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    void printList(){
        node* temp = this->head;
        while(temp!=NULL){
            cout<<temp->d<<"-";
            temp = temp->next;
        }
        cout<<endl;
        delete temp;
    }
    void buildList(){
        int data;
        cin>>data;
        while(data!=-1){
            insertAtTail(data);
            cin>>data;
        }
    }
    void insertAtTail(int data){
       node* n  = new node(data);
       n->next = NULL;
        this->tail->next= n;
        this->tail = n;
    }
    
    int lengthOfList(){
        node* temp = this->head;
        int num = 0;
        while(temp!=NULL){
            num++;
            temp = temp->next;
        }
        return num;
    }
    void insertInMiddle(int data, int pos){
        if(pos>lengthOfList()){
            cout<<"Not enough Elements";
            return;
        }else if (pos==0){
            insertAtHead(data);
            return;
        }
        node* temp = this->head;
        while(--pos){
            temp = temp->next;
        }
        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
    void deleteAtHead(){
        if(this->head==NULL){
            return;
        }
        node* n = this->head;
        this->head = this->head->next;
        delete n;
    }
    // Operator overloading not working.
    // void operator<<(ostream &os,LinkedList& l){
    //     l.printList();
    // }
    // void operator>>(istream &is, LinkedList& l){
    //     l.buildList();
    // }
    void middleElement(){
        if(this->head==NULL){
            cout<<"Empty list";
        }else if(this->head->next==NULL){
            cout<<this->head->d;
        }
        node* fast = this->head;
        node* slow = this->head;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }   
        cout<<slow->d;
    }
    void reverseLinkedList(){
        node* prev = NULL;
        node* c = this->head;
        this->tail = c;
        node* n = NULL;
        while(c!=NULL){
            n = c->next;
            c->next = prev;
            prev = c;
            c= n;
        }
        this->head = prev;
    }
    void deleteAtTail(){
        if(this->head==NULL){
            cout<<"No item in list";
        }
        node*prev = NULL;
        node* temp = this->head;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        this->tail = prev;
        prev->next = NULL;
        delete temp;
    }
    void deleteInMiddle(int pos){
        if(pos>lengthOfList()){
            cout<<"Pos more than length";
            return;
        }
        if(this->head==NULL){
            cout<<"No items in list";
            return;
        }
        node* temp = this->head;
        node* prev=NULL;
        while(--pos){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    void iterativeSearch(int data){
        node* temp = this->head;
        int index =1;
        while(temp!=NULL){
            if(temp->d==data){
                cout<<"Found on pos:"<<index;
                temp = temp->next;
                index++;
            }
        }
    }
    bool recursiveSearch(node* temp,int data){
        //How to pass a temp pointer
    }
    
    
};

int main(){
    LinkedList l;
    l.insertAtHead(5);
    l.insertAtHead(4);
    l.insertAtHead(3);
    l.insertAtTail(2);
    l.insertAtTail(7);
    l.insertInMiddle(1,0);
    l.printList();
    l.middleElement();
}
