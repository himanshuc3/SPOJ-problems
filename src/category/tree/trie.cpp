/**
 * Problem: Trie implementation.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char, node*>

class node{
    public:
        char data;
        hashmap h;
        bool isTerminal;
        
        node(char d){
            data =d;
            isTerminal = false;
        }
};

class Trie{
    node* root;
    
    public: 
        Trie(){
            root= new node('\0');
        }
        
        //insertion
        void addWord(char* word){
            node* temp = root;
            for(int i=0;word[i]!='\0';i++){
                char ch = word[i];
                // not found
                if(temp->h.count(ch)==0){
                    node* childNode = new node(ch);
                    temp->h[ch] = childNode;
                    temp = childNode;
                }else{
                    temp = temp->h[ch];
                }
            }
            temp->isTerminal = true;
        }
        //lookup
        bool search(char* word){
            node* temp = root;
            for(int i=0;word[i]!='\0';i++){
                char ch = word[i];
                if(temp->h.count(ch)){
                    temp = temp->h[ch];
                }else{
                    return false;
                }
            }
            return temp->isTerminal;
        }
};

int main() {
    char word[10][100] = {"apple","ape","coder", "coding blocks","no"};
    Trie t;
    for(int i=0;i<5;i++){
        t.addWord(word[i]);
    }
    
    char searchWord[100];
    cin.getline(searchWord,100);
    
    if(t.search(searchWord)){
        cout<<searchWord<<" found"<<endl;
    }else{
        cout<<searchWord<<" is not present"<<endl;
    }
    
	return 0;
}