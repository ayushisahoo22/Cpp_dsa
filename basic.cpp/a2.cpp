#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in array" << endl;
    cin >> n;

    int arr[100];
    cout << "Enter elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    // int length = sizeof(arr) / sizeof(arr[0]);   this will include the garbage value as the size of arr is taken as 100
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of elements of array is:" << sum;
    return 0;
}