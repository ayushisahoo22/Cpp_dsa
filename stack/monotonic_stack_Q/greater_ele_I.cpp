#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int>pre;
    stack<int>st;
    int i=nums2.size()-1;
    while(i>=0){
        while(!st.empty() && st.top()<nums2[i]){
            st.pop();
        }
        if(st.empty()){
            pre.push_back(-1);
        }else{
            pre.push_back(st.top());
        }
        st.push(nums2[i]);
        i--;
    }
    reverse(pre.begin(),pre.end());
    
    unordered_map<int,int>mpp;  //inplace of this we can use fine()
    //but that will take o(n) for every element so o(n*m)
    //map will access the elemnt in o(1)
    for(int j=0;j<nums2.size();j++){
        mpp[nums2[j]]=pre[j];
    }
    vector<int>res;
    for(auto it:nums1){
        res.push_back(mpp[it]);
    }
    return res;
}

int main(){
    int n, m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    vector<int>num1(n);
    vector<int>num2(m);
    cout<<"Enter elements of num1: ";
    for(int i=0;i<n;i++){
        cin>>num1[i];
    }
    cout<<"Enter elements of num2: ";
    for(int i=0;i<m;i++){
        cin>>num2[i];
    }
    vector<int>res=nextGreaterElement(num1,num2);
    for(auto it:res){
        cout<<it<<" ";
    }
}