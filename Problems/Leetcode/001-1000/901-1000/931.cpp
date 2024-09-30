#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> f(n, vector<int>(n + 2, INT_MAX));
        for (int i = 0; i < n; ++i) {
            f[0][i + 1] = matrix[0][i];
        }
        for (int x = 1; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                f[x][y + 1] = min({f[x - 1][y], f[x - 1][y + 1], f[x - 1][y + 2]}) + matrix[x][y];
            }
        }
        return ranges::min(f[n - 1]);
    }

    // 空间优化
    int minFallingPathSum_(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> f(n + 2, INT_MAX);
        for (int i = 0; i < n; ++i) {
            f[i + 1] = matrix[0][i];
        }
        for (int x = 1; x < n; ++x) {
            int pre = f[0];
            for (int y = 0; y < n; ++y) {
                int tmp = pre;
                pre = f[y + 1];
                f[y + 1] = min({tmp, f[y + 1], f[y + 2]}) + matrix[x][y];
            }
        }
        return ranges::min(f);
    }
};

int main() {
    Solution sol;

    return 0;
}