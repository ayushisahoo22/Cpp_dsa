#include<bits/stdc++.h>
using namespace std;

struct Job{
    int n;
    int deadline;
    int profit;
};

bool cmp(Job a,Job b){
    return a.profit>b.profit;
}

// pair<int,int>jobSchedule(Job arr[],int n){    TC->O(N^2)
//     sort(arr,arr+n,cmp);
//     int total=0;
//     int job=0;
//     int d=0;
//     for(int i=0;i<n;i++){
//         d=max(d,arr[i].deadline);
//     }
//     vector<int>newArr(d,-1);
//     for(int i=0;i<n;i++){
//         for(int j=arr[i].deadline;j>=0;j--){
//             if(newArr[j]==-1){
//                 newArr[i]=arr[i].n;
//                 job++;
//                 total+=arr[i].profit;
//                 break;
//             }
//         }
//     }
//     return {job,total};
// }

//we'll use dsu(DISJOINT SET UNION) to optimise TC to O(NlogN)
int find(int x, vector<int>& parent){
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x],parent);
}

void merge(int u,int v,vector<int>& parent){
    parent[u]=v;
}

pair<int,int>jobSchedule(Job arr[],int n){
    sort(arr,arr+n,cmp);
    int total=0;
    int job=0;
    int d=0;
    for(int i=0;i<n;i++){
        d=max(d,arr[i].deadline);
    }
    vector<int>parent(d+1);
    for(int i=0;i<=d;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        int availableSlot=find(arr[i].deadline,parent);
        if(availableSlot>0){
            job++;
            total+=arr[i].profit;
            merge(availableSlot,availableSlot-1,parent);
        }
    }
    return {job,total};
}

int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
   pair<int,int>p=jobSchedule(arr,n);
   cout<<p.first<<" "<<p.second;
   return 0;
}