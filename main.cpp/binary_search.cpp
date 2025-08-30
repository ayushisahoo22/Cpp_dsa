#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n] = {};
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<endl;
    }
    int num;
    cout << "Enter the number to search: ";
    cin >> num;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == num)
        {
            cout << num << " is at index " << mid;
            break;
        }
        else if (arr[mid] > num)
        {
            e = mid - 1;
        }
        else if (arr[mid] < num)
        {
            s = mid + 1;
        }
    }
}