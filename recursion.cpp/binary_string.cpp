#include<bits/stdc++.h>
using namespace std;

// Given an integer n, return all binary strings of length n that do not contain consecutive 1s.
// Return the result in lexicographically increasing order.

void makeString(vector<string>&res,string curr,int n){
    if(curr.size()==n){
        res.push_back(curr);
        return;
    }
    makeString(res,curr+"0",n);
    if(curr.empty() || curr.back()!='1'){
        makeString(res,curr+"1",n);
    }

}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<string>res;
    makeString(res,"",n);
    for(auto it:res){
        cout<<it<<" ";
    }
}