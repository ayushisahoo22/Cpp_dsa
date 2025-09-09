#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;vector <int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the element to search: ";
    cin>>k;
    for(int i=0;i<n;i++){
        if(nums[i]==k){
            cout<<"found at index "<<i;
        }
    }
    if(find(nums.begin(),nums.end(),k)==nums.end()){
        cout<<"Element is not present";
    }
}