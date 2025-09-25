#include <bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row){
        int ans=1;
        vector<int> sol;
        sol.push_back(ans);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            sol.push_back(ans);
        }
        return sol;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    //to print a specific value at [n][r]
    /*int n,r;
    cin>>n>>r;
    int res=1;
    for(int i=1;i<r;i++){
        res=res*(n-i);
        res=res/(i);
    }  
    cout<<res<<endl;*/

    //to print any nth row
    /*int n;
    cout<<"Enter the row number: ";
    cin>>n;
    int res=1;
    cout<<res<<" ";
    for(int i=1;i<n;i++){
        res*=(n-i);
        res/=(i);
        cout<<res<<" ";
    }*/
   
    //to print pascal triangle upto nth row
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    vector<vector<int>> ans=pascalTriangle(n);
    for(auto el:ans){
        for(auto i:el){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}



