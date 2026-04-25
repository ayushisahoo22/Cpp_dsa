#include<bits/stdc++.h>
using namespace std;

//LC-402

string removeKdigits(string num, int k) {
    int n=num.size();
    if(k==n) return "0";
    stack<char>st;
    int i=0;
    while(i<n){
        while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
            st.pop();
            k--;
        }
        st.push(num[i]);
        i++;
    }
    while(k>0){
        st.pop();
        k--;
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    while(ans.size()!=0 && ans.back()=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    return ans.empty()?"0":ans;
}

int main(){
    string num;
    cout<<"Enter num: ";
    cin>>num;
    int k;
    cout<<"Enter k: ";
    cin>>k;
    string ans=removeKdigits(num,k);
    cout<<ans;
}