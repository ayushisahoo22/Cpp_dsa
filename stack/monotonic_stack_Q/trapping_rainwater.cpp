#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int leftMax=0,rightMax=0,total=0;
    int l=0,r=height.size()-1;
    while(l<r){
        if(height[l]<=height[r]){
            if(leftMax>height[l]){
                total+=(leftMax-height[l]);
            }else{
                leftMax=height[l];
            }
            l++;
        }else{
            if(rightMax>height[r]){
                total+=(rightMax-height[r]);
            }else{
                rightMax=height[r];
            }
            r--;
        }
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
    int ans=trap(arr);
    cout<<ans;
}