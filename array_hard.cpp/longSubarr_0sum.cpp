#include<bits/stdc++.h>
using namespace std;

int zeroSum(vector<int>arr,int n){
    int maxLen=0;
    int sum=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            maxLen=i+1;
        }else{
            if(mpp.find(sum)!=mpp.end()){
                maxLen=max(maxLen,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
    }
    return maxLen;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=zeroSum(arr,n);
    cout<<ans;
}