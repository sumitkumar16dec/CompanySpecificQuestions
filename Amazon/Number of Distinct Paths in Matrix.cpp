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

Better Solution:
Time Complexity: O(n²)
Space Complexity: O(n²)

#include <iostream>
#include <vector>
using namespace std;

int countPaths(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize starting cell
    if (grid[0][0] != -1)
        dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == -1)
                dp[i][j] = 0; // cannot step into a trap
            else {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][n - 1];
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


Optimal Solution:
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




Follow-Up Question :
Now, each cell in the n × n grid either contains:
A trap, denoted by -1 — you cannot step into these cells.
A non-negative reward, denoted by any >= 0 integer — this is the reward collected when you step on the cell.
You still start from the top-left cell (0, 0) and aim to reach the bottom-right cell (n - 1, n - 1) by only moving right or down, and never stepping into trap cells (-1).
Write a function to compute the maximum total reward you can collect along a valid path from (0, 0) to (n - 1, n - 1).
If there is no valid path, return 0.

Better Solution :
Time Complexity: O(n²)
Space Complexity: O(n²)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxReward(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Initialize starting cell
    if (grid[0][0] != -1) {
        dp[0][0] = grid[0][0];
    }

    // Fill the DP table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == -1) {
                dp[i][j] = -1; // trap, unreachable
            } else {
                if (i > 0 && dp[i-1][j] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j]);
                }
                if (j > 0 && dp[i][j-1] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j]);
                }
                // For starting cell (0,0), dp[0][0] is already set above
                // For other cells, if both top and left are unreachable, dp[i][j] remains -1
            }
        }
    }

    return dp[n-1][n-1] == -1 ? 0 : dp[n-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {0,  2,  1},
        {2, -1,  3},
        {4,  2,  1}
    };

    cout << "Maximum total reward: " << maxReward(grid) << endl;
    return 0;
}

    
Optimal Solution :
Time Complexity: O(n²)
Space Complexity: O(n)
    
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxReward(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> dp(n, -1);

    // Initialize start cell
    if (grid[0][0] != -1) dp[0] = grid[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == -1) {
                dp[j] = -1; // cannot step here
            } else {
                int fromTop = (i > 0) ? dp[j] : -1;
                int fromLeft = (j > 0) ? dp[j - 1] : -1;
                int bestPrev = max(fromTop, fromLeft);

                if (bestPrev == -1) {
                    dp[j] = (i == 0 && j == 0) ? grid[0][0] : -1;
                } else {
                    dp[j] = bestPrev + grid[i][j];
                }
            }
        }
    }

    return dp[n - 1] == -1 ? 0 : dp[n - 1];
}

int main() {
    vector<vector<int>> grid = {
        {0,  2,  2},
        {1, -1,  3},
        {4,  2,  1}
    };

    cout << "Maximum total reward: " << maxReward(grid) << endl;
    return 0;
}
