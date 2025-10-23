#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//Better approach - TC-->O(N^2 log N)
//                  SC-->O(N)+2*O(Number of ele)

//TLE occur
/*vector<vector<int>> threeSum(vector<int>& nums) {
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
}*/

//Optimal approach TC-->O(NlogN)+O(N^N)
//                 SC-->O(No of unique triplets)

//eg -->[-2,-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2]
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());   //sorting the array
    for(int i=0;i<nums.size();i++){

        //if i is greater than 0 and equal to previous one skip that 
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;  
        int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){  //if sum is less than 0 we will increase j to be near to 0
                j++;
            }else if(sum>0){
                k--;   //if sum is greater than 0 we will decrease k to be near to 0
            }else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                //after storing particular i,j,k..increase j k for next triplet
                j++;
                k--;

                //if the j and k are same till a point skip that part using while
                //using j<k so it won't run endless time
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
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