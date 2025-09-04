#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the val of m and n ";
    cin>>m>>n;
    int arr1[100],arr2[100];
    cout<<"Enter element of first array: ";
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    cout<<"Enter element of second array: ";
    for(int j=0;j<n;j++){
        cin>>arr2[j];
    }

    //using map
    // map<int,int> mp;  //used map bcz it will arrange the elements in ascending order
    // vector<int> result;
    // for(int i=0;i<m;i++){
    //     mp[arr1[i]]++;
    // }
    // for(int i=0;i<n;i++){
    //     mp[arr2[i]]++;
    // }
    // for(auto it:mp){
    //     result.push_back(it.first);
    // }


    //using set
    // set<int> s;
    // vector<int> result;
    // for(int i=0;i<m;i++){
    //     s.insert(arr1[i]);
    // }
    // for(int j=0;j<n;j++){
    //     s.insert(arr2[j]);
    // }
    // for(auto it:s){
    //     result.push_back(it);
    // }


    vector<int>result;
    //initially push all elements of arr1
    for(int i=0;i<m;i++){
        result.push_back(arr1[i]);
    }
    //if element is not present already then only push from arr2
    for(int i=0;i<n;i++){
        if(find(result.begin(),result.end(),arr2[i])==result.end()){
            result.push_back(arr2[i]);
        }
    }
    //for sorting in ascending order
    sort(result.begin(),result.end());

    //displaying union
    int size=result.size();
    for(int i=0;i<size;i++){
        cout<<result[i]<<" ";
    }

}