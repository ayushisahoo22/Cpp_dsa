#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i=0,sign=1;
    long long ans=0;
    while(i<s.size() && s[i]==' '){
        i++;
    }
    if(i==s.size()) return 0;
    if(s[i]=='-'){
        sign=-1;
        i++;
    }else if(s[i]=='+'){
        sign=1;
        i++;
    }
    while(i<s.size() && isdigit(s[i])){
        ans=ans*10+(s[i]-'0');
        if(sign*ans>INT_MAX) return INT_MAX;
        if(sign*ans<INT_MIN) return INT_MIN;
        i++;
    }
    return (int)(sign*ans);
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int ans=myAtoi(s);
    cout<<ans;
}