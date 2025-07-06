Question:
Given an integer array arr and an integer k, generate an output list where the i-th element is the k-th largest number among the first i + k elements of arr.
Specifically, start from the k-th index (0-based) of the array and, for each sublist formed by taking elements from index k up to the current index, find the k-th largest number in that sublist.

Input:
arr = [4, 2, 1, 3]
k = 2
  
Output:
[2, 2, 3]
  
Explanation:
For the first element, sublist is [4, 2]. The 2nd largest number is 2.
For the second element, sublist is [4, 2, 1]. The 2nd largest number is 2.
For the third element, sublist is [4, 2, 1, 3]. The 2nd largest number is 3.

Time Complexity: O(n log k)
Space Complexity: O(k)

#include <bits/stdc++.h>
using namespace std;

vector<int> findKthLargestFromK(vector<int>& arr, int k) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); ++i) {
        if (minHeap.size() < k) {
            minHeap.push(arr[i]);
        } else if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        if (i >= k - 1) {
            result.push_back(minHeap.top());
        }
    }
    return result;
}

int main() {
    vector<int> arr = {4, 2, 1, 3};
    int k = 2;
    vector<int> ans = findKthLargestFromK(arr, k);

    cout << "Output: [";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
