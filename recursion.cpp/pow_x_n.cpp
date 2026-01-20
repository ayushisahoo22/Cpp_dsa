#include<bits/stdc++.h>
using namespace std;

// implement pow(x,n)

class Solution {
private:
    double power(double x, long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        // If 'n' is even
        if (n % 2 == 0) {
            // Recursive call: x * x, n / 2
            return power(x * x, n / 2);
        }
        // If 'n' is odd
        // Recursive call: x * power(x, n-1)
        return x * power(x, n - 1);
    }

public:
    double myPow(double x, int n) {
        int num = n;
        if (num < 0) {
            return (1.0 / power(x, -1 * num));
        }
        return power(x, num);
    }
};

int main() {
    Solution sol;
    double x = 2.0;
    int n = 10;
    double result = sol.myPow(x, n);

    // Print the result
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}