#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
static constexpr int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector memo(k + 1, vector(n, vector<double>(n)));
        auto dfs = [&](auto&& dfs, int k, int i, int j) -> double {
            if (i < 0 || i >= n || j < 0 || j >= n) {
                return 0;
            }
            if (k == 0) {
                return 1;
            }
            double& res = memo[k][i][j];
            if (res) {
                return res;
            }
            for (int a = 0; a < 8; ++a) {
                res += dfs(dfs, k - 1, i + dx[a], j + dy[a]);
            }
            res /= 8;
            return res;
        };
        return dfs(dfs, k, row, column);
    }
};

int main() {
    Solution sol;

    return 0;
}