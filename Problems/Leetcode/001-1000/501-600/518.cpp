#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int n = coins.size();

        // vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        // function<int(int, int)> dfs = [&](int i, int c) -> int {
        //     if (i < 0) {
        //         return c == 0 ? 1 : 0;
        //     }

        //     int& res = memo[i][c];
        //     if (res != -1) {
        //         return res;
        //     }

        //     if (c < coins[i]) {
        //         return res = dfs(i - 1, c);
        //     } else {
        //         return res = dfs(i - 1, c) + dfs(i, c - coins[i]);
        //     }
        // };

        // int ans = dfs(n - 1, amount);
        // return max(ans, 0);

        vector<int> f(amount + 1);
        f[0] = 1;
        for (const int& coin : coins) {
            for (int c = coin; c <= amount; ++c) {
                f[c] += f[c - coin];
            }
        }

        return f[amount];
    }
};
