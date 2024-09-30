#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> f(n + 1);
        for (int i = 0; i < m; ++i) {
            f[0] = i == 0 ? (obstacleGrid[0][0] == 0) : 0;
            for (int j = 0; j < n; ++j) {
                f[j + 1] = obstacleGrid[i][j] == 0 ? f[j + 1] + f[j] : 0;
            }
        }
        return f[n];
    }
};

int main() {
    vector<vector<int>> obstacleGrid {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}