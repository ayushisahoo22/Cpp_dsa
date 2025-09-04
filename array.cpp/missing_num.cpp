#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool found;
    unordered_map<int,bool> mpp;
    for(int i=1;i<=n;i++){
        if(find(arr.begin(),arr.end(),i)!=arr.end()){
            found=1;
            mpp[i]=found;
        }else{
            found=0;
            mpp[i]=found;
        }
    }
    for(auto it:mpp){
        if(it.second==0){
            cout<<"Missing number is: "<<it.first<<endl;
        }
    }
    return 0;
}