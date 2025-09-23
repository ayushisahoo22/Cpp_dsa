#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout << "Enter the size of array ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout<<"Enter the k: ";
    cin>>k;
    int presum=0,count=0;
    map<int,int>mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        count+=mpp[presum-k];
        mpp[presum]+=1;
    }
    cout<<count;
}