#include<bits/stdc++.h>
using namespace std;

//check whether the kth bit of n is set or not
// 0 based lsd

int main(){
    int n,k;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter kth bit: ";
    cin>>k;
    if(((n>>k)&1)==1){
        cout<<"true";
    }else{
        cout<<"false";
    }
}