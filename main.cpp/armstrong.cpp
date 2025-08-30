#include <iostream>
using namespace std;
#include <cmath>
bool isArmstrong(int n) {
        int cnt =0,sum=0;
        int orig=n,t=n;
        while(n>0){
            cnt+=1;
            n=n/10;
        }
        while(t>0){
            int rem = t%10;
            sum=sum+(int)(round(pow(rem,cnt)));
            t=t/10;
        }
        if(sum==orig) return true;
        else return false;
}
int main(){
    int n,y;
    cout<<"Enter n ";
    cin>>n;
    bool s = isArmstrong(n);
    cout<<s;
}