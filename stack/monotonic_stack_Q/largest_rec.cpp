#include<bits/stdc++.h>
using namespace std;

vector<int>findPSE(vector<int>arr){
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
vector<int>findNSE(vector<int>arr){
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    vector<int>a1=findPSE(heights);
    vector<int>a2=findNSE(heights);
    int maxi=0;
    for(int i=0;i<heights.size();i++){
        maxi=max(maxi,heights[i]*(a2[i]-a1[i]-1));
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans=largestRectangleArea(arr);
    cout<<ans;
}