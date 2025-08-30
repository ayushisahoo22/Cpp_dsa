#include <iostream>
using namespace std;
#include <cmath>

//string
// void pallindrome(string s){
//     int n=s.size();
//     bool pal = true;
//     for(int i=0;i<n;i++){
//         if(s[i]!=s[n-i-1]){
//             pal=false;
//         }
//     }
//     if(pal) cout<<"true";
//     else cout<<"false";
// }
// int main(){
//     string s;
//     cout<<"Enter a string: ";
//     cin>>s;
//     pallindrome(s);
// }

//number
bool isPalindrome(int n) {
    int t=n;
    int s =0;
    while(n!=0){
        int x=n%10;
        s=s*10+x;
        n=n/10;
    }
    if(t==s) cout<<"true";
    else cout<<"false";
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    isPalindrome(n);
}