#include <iostream>
using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the value of n:";
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cout<<"Enter the value of n:";
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cout<<"Enter the value of n:";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter the value of n:";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i+1;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }


//combining two diff pattern1 and pattern2
// void pattern1(int n){
//     for(int i=0;i<n;i++){
//         //space
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         //star
//         for(int j=0;j<(2*i+1);j++){
//             cout<<"*";
//         }
//         //space
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }
// void pattern2(int n){
//     for(int i=0;i<n;i++){
//         //space
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         //star
//         for(int j=0;j<2*n-(2*i+1);j++){
//             cout<<"*";
//         }
//         //space
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter the value of n:";
//     cin>>n;
//     pattern1(n);
//     pattern2(n);
// }


// int main(){
//     int n;
//     cout<<"Enter the no of rows: ";
//     cin>>n;
//     int start=1;
//     for(int i=1;i<=n;i++){
//         if(i%2!=0) start=1;
//         else start=0;
//         for(int j=1;j<=i;j++){
//             cout<<start;
//             start = 1-start;
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         //number
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         //space
//         for(int j=0;j<2*(n-i);j++){
//             cout<<" ";
//         }
//         //number
//         for(int j=i;j>=1;j--){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     int start=1;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<start<<" ";
//             start=start+1;
//         }
//         cout<<endl;
//     }
// }