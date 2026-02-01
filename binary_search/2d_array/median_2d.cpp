#include<bits/stdc++.h>
using namespace std;

//find median of 2d matrix where rows are sorted only

int findMedian(vector<vector<int>>mat){
    int n=mat.size();
    int m=mat[0].size();
    int low=INT_MAX, high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }
    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        if(cnt<=req){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 7},
        {2, 7, 9},
        {3, 6, 9}
    };
    int ans=findMedian(matrix);
    cout<<ans;
}