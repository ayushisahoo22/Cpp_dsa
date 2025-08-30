#include <iostream>
using namespace std;

bool isPallindrome(string s,int n,int i){
    if(s[i]!=s[n-i-1]) return false;
    if(i>=n/2) return true;
    isPallindrome(s,n-1,i+1);
}
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int n=s.size();
    bool y = isPallindrome(s,n,0);
    cout<<y;
}