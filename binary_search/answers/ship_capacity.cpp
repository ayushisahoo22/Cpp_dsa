#include<bits/stdc++.h>
using namespace std;

int needed(vector<int>weights,int capacity){
    int days=1;
    int curr=0;
    for(auto it:weights){
        if((curr+it)>capacity){
            days++;
            curr=it;
        }else{
            curr+=it;
        }
    }
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low=*max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        int d=needed(weights,mid);
        if(d<=days){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n,d;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter days: ";
    cin>>d;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=shipWithinDays(arr,d);
    cout<<ans;
}