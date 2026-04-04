#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& arr, int target) {
    sort(arr.begin(),arr.end());
    int mini=arr[0]+arr[1]+arr[2];
    for(int i=0;i<arr.size();i++){
        int j=i+1;
        int k=arr.size()-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(abs(sum-target)<=abs(mini-target)){
                mini=sum;
            }
            if(sum<target) j++;
            else if(sum>target) k--;
            else return sum;
        }
    }
    return mini;
}

int main(){
    int n,t;
    cout<<"Enter n and t: ";
    cin>>n>>t;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=threeSumClosest(arr,t);
    cout<<ans;
}