#include <bits/stdc++.h> 
using namespace std;

vector<int> radixSort(int n, vector<int>& arr) {
    int maxi=*max_element(arr.begin(),arr.end());
    for(int exp=1;maxi*exp>0;exp*=10){
        vector<int>output(n);
        int count[10]={0};
        for(int i=0;i<n;i++){
            int dig=(arr[i]/exp)%10;
            count[dig]++;
        }
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            int dig=(arr[i]/exp)%10;
            output[count[dig]-1]=arr[i];
            count[dig]--;
        }
        for(int i=0;i<n;i++){
            arr[i]=output[i];
        }
    }
    return arr;
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
    vector<int> res=radixSort(n,arr);
    for(auto it:res){
        cout<<it<<" ";
    }
}