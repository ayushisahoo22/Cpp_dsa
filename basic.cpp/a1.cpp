#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size];

    // Fill all elements with 7
    for(int i = 0; i < size; ++i) {
        arr[i] = 7;
    }

    // Print to check
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}