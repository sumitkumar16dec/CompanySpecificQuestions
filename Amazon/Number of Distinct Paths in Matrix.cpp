Question:
You are given an n × n grid. Some of the cells may contain traps, denoted by '-1', and the rest are free cells, denoted by '0'.
You start from the top-left corner (0, 0) and want to reach the bottom-right corner (n - 1, n - 1).
You can only move right or down at any step, and you cannot move into cells with traps.
Write a function to determine the number of distinct paths from the top-left to the bottom-right of the grid.

Input:
{0,  0,  0},
{0, -1,  0},
{0,  0,  0}

Ouput: 2

Time Complexity: O(n²)
Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int countPaths(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> dp(n, 0);

    // Initialize starting cell
    dp[0] = (grid[0][0] != -1) ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == -1) {
                dp[j] = 0;  // trap cell, cannot reach here
            } else {
                if (j > 0)
                    dp[j] += dp[j - 1];  // from left
                // dp[j] already has value from top
            }
        }
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> grid = {
        {0,  0,  0},
        {0, -1,  0},
        {0,  0,  0}
    };

    cout << "Number of distinct paths: " << countPaths(grid) << endl;
    return 0;
}

