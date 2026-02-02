#include<bits/stdc++.h>
using namespace std;

//set rightmost unset bit if there exist any unset bit in n
//else return the n directly

int setBit(int n){
    //111 return direct
    //7 & 8= 0
    if((n&(n+1))==0) return n;
    return (n|(n+1));
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=setBit(n);
    cout<<ans;
}