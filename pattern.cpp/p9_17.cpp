#include <iostream>
using namespace std;

// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     char ch='A';
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<char(ch+j)<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(char ch='A';ch<'A'+n-i;ch++){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     char ch='A';
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<ch<<" ";
//         }
//         ch=ch+1;
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     for(int i=0;i<n;i++){
//         char ch='A';
//         //space
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         //characters
//         int breakPoint = (2*i+1)/2;
//         for(int j=1;j<=(2*i+1);j++){
//             cout<<ch;
//             if(j<=breakPoint) ch++;
//             else ch--;

//         }
//          //space 
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     int ch = 65+n;
//     for(int i=0;i<n;i++){
//         for(char ch='E'-i;ch<='E';ch++){
//             cout<<ch;
//         }
//         cout<<endl;
//     }
// }


// void p1(int n){
//     int inSp=0;
//     for(int i=1;i<=n;i++){
//         //star
//         for(int j=1;j<=n-i+1;j++){
//             cout<<"*";
//         }
//         //space
//         for(int j=0;j<inSp;j++){
//             cout<<" ";
//         }
//         //star
//         for(int j=1;j<=n-i+1;j++){
//             cout<<"*";
//         }
//         inSp+=2;
//         cout<<endl;
//     }
// }
// void p2(int n){
//     for(int i=1;i<=n;i++){
//         //star
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         //space
//         for(int j=0;j<2*(n-i);j++){
//             cout<<" ";
//         }
//         //star
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     p1(n);
//     p2(n);
// }


// void pat2(int n){
//     int insp=2*n-2;
//     for(int i=1;i<=2*n-1;i++){
//         int star=i;
//         if(i>n) star = 2*n-i;
//         //star
//         for(int j=1;j<=star;j++){
//             cout<<"*";
//         }
//         //space
//         for(int j=0;j<insp;j++){
//             cout<<" ";
//         }
//         //star
//         for(int j=1;j<=star;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//         if(i<n) insp-=2;
//         else insp+=2;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     pat2(n);
// }


// void patt1(int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(i==0 || j==0 || i==n-1 || j==n-1){
//                 cout<<"*";
//             }
//             else cout<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     patt1(n);
// }