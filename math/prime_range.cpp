#include<bits/stdc++.h>
using namespace std;

//print all the prime no till n
//sieve of eratosthenes method

vector<int>primeNo(int n){
    vector<int>res;
    vector<int>prime(n+1,1);
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==1) res.push_back(i);
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>res=primeNo(n);
    for(auto it:res){
        cout<<it<<" ";
    }
}