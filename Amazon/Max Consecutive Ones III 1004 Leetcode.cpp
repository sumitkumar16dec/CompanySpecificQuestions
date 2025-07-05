Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Time: O(N) → each index visited at most twice (by right and left).
Space: O(1) → only a few variables.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeros = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) zeros++;
            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (0 or 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter value of k (maximum number of zeros you can flip): ";
    cin >> k;

    Solution sol;
    int result = sol.longestOnes(nums, k);

    cout << "Longest subarray with at most " << k << " zeros flipped: " << result << endl;

    return 0;
}
