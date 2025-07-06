Input: 
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
Output : 1

✅ Time Complexity:
We start from the top-right corner and move either left or down each time.
So, total number of steps is at most n + m (since we can’t go up or right).
O(n + m).

✅ Space Complexity:
We use only a few extra variables, so:
O(1).

#include <iostream>
#include <vector>
using namespace std;

int rowWithMaxOnes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return -1;
    int m = matrix[0].size();
    
    int max_row_index = -1;
    int j = m - 1;  // Start from top-right corner

    for (int i = 0; i < n; i++) {
        while (j >= 0 && matrix[i][j] == 1) {
            j--;
            max_row_index = i;
        }
    }

    return max_row_index;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMaxOnes(matrix);
    cout << "Row with maximum ones is: " << result << endl;

    return 0;
}

For counting no. of ones also, add "cnt=m-j-1;" in line 32 after initializing cnt variable at top
