#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int cnt=0;

    //method-1
    // while(n>1){
    //     if(n&1){
    //         cnt++;
    //     };
    //     n=n>>1;
    // }
    // if(n==1) cnt++;

    //method2
    while(n!=0){
        n= n& (n-1);
        cnt++;
    }
    cout<<cnt;
}