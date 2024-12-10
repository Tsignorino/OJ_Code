#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

const vector<int> NEXT[10] {
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {0, 3, 9},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4}
};
static constexpr int MOD = 1'000'000'007;

vector<vector<int>> memo;
auto init = []() {
    memo.resize(5010, vector<int>(10));
    return 0;
}();
int dfs(int i, int j) {
    if (i == 0) {
        return 1;
    }
    int& res = memo[i][j];
    if (res) {
        return res;
    }
    for (int k : NEXT[j]) {
        res = (res + dfs(i - 1, k)) % MOD;
    }
    return res;
}

class Solution {
public:
    int knightDialer(int n) {
        // 无法从 5 号移动到其他单元格
        if (n == 1) {
            return 10;
        }

        int ans = 0;
        for (int j = 0; j < 10; ++j) {
            ans = (ans + dfs(n - 1, j)) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}