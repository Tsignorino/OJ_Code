#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //* 记忆化搜索
        // int n = coins.size();
        // vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        // function<int(int, int)> dfs = [&](int i, int c) -> int {
        //     if (i < 0) {
        //         return c == 0 ? 0 : INT_MAX / 2;
        //     }

        //     int& res = memo[i][c];
        //     if (res != -1) {
        //         return res;
        //     }

        //     if (c < coins[i]) {
        //         return res = dfs(i - 1, c);
        //     }
        //     return res = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
        // };

        // int ans = dfs(n - 1, amount);
        // return ans < INT_MAX / 2 ? ans : -1;

        //* 递推
        vector<int> f(amount + 1, INT_MAX / 2);
        f[0] = 0;
        for (const int& v : coins) {
            for (int c = v; c <= amount; ++c) {
                f[c] = min(f[c], f[c - v] + 1);
            }
        }
        int ans = f[amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }
};