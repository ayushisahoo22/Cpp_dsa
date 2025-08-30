#include <iostream>
using namespace std;
int fact(int num){
    int ans = 1;
    for(int i=num;i>=1;i--){
        ans= ans*i;
    }
    return ans;
}
int nCr(int n,int r){

    int ans = fact(n)/(fact(r)*fact(n-r));
    cout<<"nCr of "<<n <<" and "<< r<<" is "<< ans<<endl;
}
int main(){
    nCr(8,0);
    nCr(7,2);
}