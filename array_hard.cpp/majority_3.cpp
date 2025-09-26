#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans;
    map<int,int>mpp;
    int mini=(n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        //CHECKING BY MINI AND PUSHING IT IN ans..This reduces TC
        //if we iterate over every element to check if its occ is >n/3  [TC-->O(NlogN+N) for map]
        //But now it only take TC-->O(N)
        if(mpp[arr[i]]==mini){
            ans.push_back(arr[i]);
        }
        //AS THERE WILL BE TWO ELEMENTS IN ans ONLY
        if(ans.size()==2){
            break;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}