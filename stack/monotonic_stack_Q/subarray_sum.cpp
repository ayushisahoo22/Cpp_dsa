#include<bits/stdc++.h>
using namespace std;

vector<int>findNSE(vector<int>arr){
    stack<int>st;
    int n=arr.size();
    vector<int>res(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        res[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return res;
}

vector<int>findPSE(vector<int>arr){
    stack<int>st;
    int n=arr.size();
    vector<int>res(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        res[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return res;
}

int countSum(vector<int>arr){
    vector<int>nse=findNSE(arr);
    vector<int>pse=findPSE(arr);
    int total=0;
    int mod=1e9+7;
    for(int i=0;i<arr.size();i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        long long freq=left*right*1LL;
        int val=(freq*arr[i]*1LL)%mod;
        total=(total+val)%mod;
    }
    return total;
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
    int sum=countSum(arr);
    cout<<sum;
}