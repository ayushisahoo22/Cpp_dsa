#include<bits/stdc++.h>
using namespace std;

//Find XOR of numbers from L to R
int xorOfRange(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
}

int main(){
    int l,r;
    cout<<"Enter l and r: ";
    cin>>l>>r;
    int first=xorOfRange(l-1);
    int second=xorOfRange(r);
    int ans=first^second;
    cout<<ans;
}