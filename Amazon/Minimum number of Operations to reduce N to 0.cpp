https://www.geeksforgeeks.org/dsa/min-number-of-operations-to-reduce-n-to-0-by-subtracting-any-digits-from-n/
You are given a positive integer n. In one operation, you are allowed to subtract any one digit (from the decimal representation of n) from n itself.
Your goal is to reduce the number to 0 using the minimum number of operations.

Example -
I/o -> 27
o/p -> 5

TC: O(nlogn), SC: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the minimum number of operations to reduce n to 0
int minOperations(int n) {
    vector<int> dp(n + 1, 1e9);  // dp[x]: min steps to reduce x to 0
    dp[0] = 0; // base case

    for (int x = 1; x <= n; ++x) {
        int num = x;
        while (num > 0) {
            int d = num % 10;  // extract last digit
            num /= 10;
            if (d > 0 && x - d >= 0) {
                dp[x] = min(dp[x], dp[x - d] + 1);
            }
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Minimum number of operations: " << minOperations(n) << endl;
    return 0;
}
