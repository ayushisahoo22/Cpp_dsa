#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//Better approach - TC-->O(N^2 log N)
//                  SC-->O(N)+2*O(Number of ele)

//TLE occur
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>>st;
    for(int i=0;i<nums.size();i++){
        set<int>val;
        for(int j=i+1;j<nums.size();j++){
            int third=-(nums[i]+nums[j]);
            if(val.find(third) != val.end()){
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            val.insert(nums[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>result=threeSum(arr);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){   //for printing result from 2D vector
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}