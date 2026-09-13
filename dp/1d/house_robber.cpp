#include<bits/stdc++.h>
using namespace std;

//space optimization SC->O(1)
int maxSum(vector<int>arr){
    int n=arr.size();
    int prev=arr[0];
    int prev2=0;
    for(int i=1;i<arr.size();i++){
        int take=arr[i]+prev2;
        int noTake=prev;
        int curr=max(take,noTake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main(){
    vector<int> arr = {3, 2, 5, 10, 7};
    cout <<maxSum(arr)<< endl;
    return 0;
}