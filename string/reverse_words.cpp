#include<bits/stdc++.h>
using namespace std;

// Given an input string s, reverse the order of the words.
// Return a string of the words in reverse order concatenated by a single space.
//note-s may contain leading or trailing spaces or multiple spaces between two words.

string reverseWords(string s) {
    int n=s.size();
    reverse(s.begin(),s.end());
    int i=0,j=0;
    while(j<n){
        while(j<n && s[j]==' ') j++;
        if(j>=n) break;
        int start=i;
        while(j<n && s[j]!=' '){
            s[i++]=s[j++];
        }
        reverse(s.begin()+start,s.begin()+i);
        s[i++]=' ';
    }
    if(i>0) i--;
    return s.substr(0,i);
}

int main(){
    string s;
    getline(cin,s);
    string result=reverseWords(s);
    cout<<result;
}