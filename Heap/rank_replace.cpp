#include<bits/stdc++.h>
using namespace std;

// vector<int>replaceRank(vector<int>arr){              tc->o(n^2)
//     priority_queue<int,vector<int>,greater<int>>pq;
//     vector<int>res(arr.size());
//     int cnt=1;
//     for(auto it:arr){
//         pq.push(it);
//     }
//     while(!pq.empty()){
//         int val=pq.top();
//         pq.pop();
//         auto it=find(arr.begin(),arr.end(),val);
//         int index=it-arr.begin();
//         res[index]=cnt;
//         cnt++;
//     }
//     return res;
// }

vector<int>replaceRank(vector<int>arr){          //tc->o(nlogn)
    vector<int>dummy=arr;
    sort(dummy.begin(),dummy.end());
    unordered_map<int,int>mpp;
    int rank=1;
    for(auto it:dummy){
        if(mpp.find(it)==mpp.end()){
            mpp[it]=rank;
            rank++;
        }
    }
    vector<int>res(arr.size());
    for(int i=0;i<dummy.size();i++){
        res[i]=mpp[arr[i]];
    }
    return res;
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
    vector<int>res=replaceRank(arr);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}