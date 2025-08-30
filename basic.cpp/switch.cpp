#include <iostream>
using namespace std;
// int main(){
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     switch(n){
//         case 1: cout<<"First";
//                 break;
//         case 2: cout<<"Second"<<endl;
//                 break;
//         case 3: cout<<"Third"<<endl;
//                 break;
//         case 4: cout<<"Fourth"<<endl;
//                 break;
//     }
// }


int main(){
    int choice = 1;
    int price = 5051;
    switch(choice){

        case 1:{
            int hund = price/100;
            price = price-hund*100;
            cout<< "Hundred rupees notes: "<< hund<<endl;
        }

        case 2:{
            int fif = price/50;
            price = price-fif*50;
            cout<< "Fifty rupees notes: "<< fif<<endl;
        }
        case 3:{
            int twe = price/20;
            price = price-twe*20;
            cout<< "ten rupees notes: "<< twe<<endl;
        }
        case 4: {
            int one = price/1;
            price = price-one*1;
            cout<< "one rupees notes: "<< one<<endl;
        }
    }
}