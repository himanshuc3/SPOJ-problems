/**
 * Problem: Hacker blocks - Recursion Obedient Problem.
 */

#include<bits/stdc++.h>
using namespace std;

bool check(string str,int curr,char lastCharacter)
{
    // if we reach last character, it follows all rules
     if(curr==str.length())
          return true;
    // Rule 1. first character is 'a'
     if(curr==0&&str[curr]=='a')
          return check(str,curr+1,'a');
    // Rule 2. 'a' is followed by 'bb'
     if(lastCharacter=='a'&&str[curr]=='b'&&str[curr+1]=='b')
        return check(str,curr+2,'b');
    // Rule 2. 'a' is followed by 'a'
    if(lastCharacter=='a'&&str[curr]=='a')
          return check(str,curr+1,'a');
    // Rule 3. 'b' is followed by 'a'
     if(lastCharacter=='b'&&str[curr]=='a')
          return check(str,curr+1,'a');
     return false;
}

int main()
{
     string str;
     cin>>str;

     if(check(str,0,'a'))
          cout<<"true";
     else
          cout<<"false";
}