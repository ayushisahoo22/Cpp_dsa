#include<bits/stdc++.h>
using namespace std;

vector<int>findNSE(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    int i=n-1;
    while(i>=0){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i]= st.empty()?n:st.top();
        st.push(i);
        i--;
    }
    return ans;
}
vector<int>findPSEE(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    int i=0;
    while(i<n){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]= st.empty()?-1:st.top();
        st.push(i);
        i++;
    }
    return ans;
}
long long smallest(vector<int>arr){
    vector<int>a1=findNSE(arr);
    vector<int>a2=findPSEE(arr);
    int n = arr.size();  
    long long sum = 0;
    for(int i=0; i < n; i++) {
        int left = i - a2[i];
        int right = a1[i] - i;
        long long freq = left*right*1LL;
        long long val = (freq*arr[i]*1LL);
        sum+=val;
    }
    return sum;
}
vector<int>findNGE(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    int i=n-1;
    while(i>=0){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        ans[i]= st.empty()?n:st.top();
        st.push(i);
        i--;
    }
    return ans;
}
vector<int>findPGEE(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    int i=0;
    while(i<n){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        ans[i]= st.empty()?-1:st.top();
        st.push(i);
        i++;
    }
    return ans;
}
long long largest(vector<int>arr){
    vector<int>a1=findNGE(arr);
    vector<int>a2=findPGEE(arr);
    int n = arr.size();  
    long long sum = 0;
    for(int i=0; i < n; i++) {
        int left = i - a2[i];
        int right = a1[i] - i;
        long long freq = left*right*1LL;
        long long val = (freq*arr[i]*1LL);
        sum+=val;
    }
    return sum;
}
long long subArrayRanges(vector<int>& nums) {
    return largest(nums)-smallest(nums);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans=subArrayRanges(arr);
    cout<<ans;
}