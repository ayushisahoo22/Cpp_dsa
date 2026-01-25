#include<bits/stdc++.h>
using namespace std;

//sort stack in decreasing order using recursion

void insert(stack<int>&s,int val){
    if(s.empty() || s.top()<=val){
        s.push(val);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,val);
    s.push(temp);
}

void sortStack(stack<int>&s){
    if(s.empty()) return;
    int val=s.top();
    s.pop();
    sortStack(s);
    insert(s,val);
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    stack<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}