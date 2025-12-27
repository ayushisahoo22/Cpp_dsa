#include<bits/stdc++.h>
using namespace std;

vector<int> findNum(vector<int> arr,int n){
    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=arr[i];
        S2+=(long long)arr[i]* (long long)arr[i];
    }
    long long val1=S-SN;  //(x-y)
    long long val2=S2-S2N;   //(x^2 - y^2)=(x-y)*(x+y)
    val2=val2/val1;   //(x+y)

    // x-y=val1
    // x+y=val2
    long long x=(val1+val2)/2;
    long long y= val2-x;
    return {(int)x,(int)y};
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result=findNum(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
    //first one is repeating
    //second one is missing
}