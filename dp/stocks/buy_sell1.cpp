#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>arr,int n){
    int profit=0;
    int curr=0;
    int mini=arr[0];
    for(int i=1;i<n;i++){
        curr=arr[i]-mini;
        profit=max(profit,curr);
        mini=min(arr[i],mini);
    }
    return profit;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=maxProfit(arr,n);
    cout<<ans;
}