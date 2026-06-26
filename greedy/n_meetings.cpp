#include<bits/stdc++.h>
using namespace std;

vector<int>meetings(vector<int>start,vector<int>end,int n){
    vector<int>res;
    int endTime=0;
    for(int i=0;i<n;i++){
        if(start[i]>endTime){
            res.push_back(i+1);
            endTime=end[i];
        }
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>start;
    vector<int>end;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        start.push_back(x);
        end.push_back(y);
    } 
    vector<int>res=meetings(start,end,n);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}