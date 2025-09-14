#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ans=fibo(n);
    cout<<ans;
}