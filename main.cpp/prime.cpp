#include <iostream>
#include <cmath>
using namespace std;
void isPrime(int n) {
    bool prime = true;
    for(int i=2;i<n;i++){
        if(n%i==0){
            prime = false;
            break;
        }
    }
    if(prime) cout<<"true";
    else cout<<"false";
    
}
int main(){
    int n,y;
    cout<<"Enter n ";
    cin>>n;
    isPrime(n);
}