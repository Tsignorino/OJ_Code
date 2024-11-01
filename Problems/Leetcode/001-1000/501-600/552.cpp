#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;
static constexpr int N = 1e5 + 1;

int memo[N][2][3];
int dfs(int i, int j, int k) {
    if (i == 0) {
        return 1;
    }

    int& res = memo[i][j][k];
    if (res) {
        return res;
    }

    res = dfs(i - 1, j, 0); // P
    if (j == 0) {
        res = (res + dfs(i - 1, 1, 0)) % MOD; // A
    }
    if (k < 2) {
        res = (res + dfs(i - 1, j, k + 1)) % MOD; // L
    }
    return res;
}

class Solution {
public:
    int checkRecord(int n) {
        // 最多有一个 A, 最多有两个连续的 L
        return dfs(n, 0, 0);
    }
};

int main() {
    Solution sol;

    return 0;
}