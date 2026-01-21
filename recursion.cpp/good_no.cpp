#include<bits/stdc++.h>
using namespace std;

// A digit string is good if the digits (0-indexed) at even indices are even 
// and the digits at odd indices are prime (2, 3, 5, or 7).

// Given an integer n, return the total number of good digit strings of length n. 
// Since the answer may be large, return it modulo 109 + 7.

const int MOD=1e9 +7;
long long power(long long x,long long n){
    if(n==0) return 1;
    long long half=power(x,n/2);
    if(n%2==0){
        return (half*half)%MOD;
    }
    return (x*half*half)%MOD;
}
int countGoodNumbers(long long n) {
    long long even=(n+1)/2;
    long long odd=n-even;
    long long ans= power(5,even);
    ans= (ans*power(4,odd))%MOD;
    return (int)ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=countGoodNumbers(n);
    cout<<ans;
}