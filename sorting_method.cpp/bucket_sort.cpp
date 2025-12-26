#include<bits/stdc++.h>
using namespace std;

// TC->O(N)  best/avrg   
// TC->O(N^2) worst [when all elements are in one bucket]

//bucket sort can be used when elements are uniformly distributed b/w a fixed range like [0,1]

void bucketSort(vector<double> &arr,int n){
    //creating n empty buckets
    vector<vector<double>> buckets(n);

    //put elements into bucket
    for(int i=0;i<n;i++){
        int indx=n*arr[i];
        if(indx==n) indx--;
        buckets[indx].push_back(arr[i]);
    }

    //sort each bucket
    for(int i=0;i<n;i++){
        sort(buckets[i].begin(),buckets[i].end());
    }

    //concatenating the buckets into arr
    int k=0;
    for(int i=0;i<n;i++){
        for(auto it:buckets[i]){
            arr[k++]=it;
        } 
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<double> arr;
    for(int i=0;i<n;i++){
        double x;
        cin>>x;
        arr.push_back(x);
    }
    bucketSort(arr,n);
    for(auto it:arr){
        cout<<it<<" ";
    }
}