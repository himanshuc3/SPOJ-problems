#include <bits/stdc++.h>
using namespace std;

void RPN(string s){
    stack<char> stk;
    map<char, int> m;
    m['+'] = 0;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 3;
    m['^'] = 4;
    unsigned int len = s.length();
    for(unsigned int i=0;i<len;i++){
        if(s[i]=='('){ 
                stk.push(s[i]);
        }else if(s[i]==')'){
                while(stk.top()!='('){
                    cout<<stk.top();
                    stk.pop();
                }
                stk.pop();
        }else if(s[i] =='^' ||
                s[i] == '*' ||
                s[i] == '/' ||
                s[i] == '+' ||
                s[i] == '-'){
                    char top = stk.top();
                    if(!stk.empty()&&top!='('&&m[top]>=m[s[i]]){
                        cout<<top;
                        stk.pop();
                        top = stk.top();
                    }
                    stk.push(s[i]);
        }else{
            cout<<s[i];
        }
        
    }
    while(!stk.empty()){
            cout<<stk.top();
            stk.pop();
        }
}

int main() {
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        RPN(s);
        cout<<endl;
    }
}
