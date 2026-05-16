#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=ans) ans=min(nums[mid],ans);
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
        }
        if(nums[mid]<=nums[high]){
            ans=min(ans,nums[mid]);
            high=mid-1;
        }else{
            ans=min(ans,nums[low]);
            low=mid+1;
        }
    }
    return ans;
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
    int ans=findMin(arr);
    cout<<ans;
}