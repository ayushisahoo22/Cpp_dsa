#include<bits/stdc++.h>
using namespace std;

//check if n is power of 2 or not
//any no as power of 2 will only contain a single set bit

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if((n &(n-1)) == 0){
        cout<<"true";
    }else{
        cout<<"false";
    }
}