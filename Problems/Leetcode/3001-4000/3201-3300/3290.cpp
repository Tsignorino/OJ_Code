#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    using ll = long long;

    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> f(5, LLONG_MIN / 2);
        f[0] = 0;
        for (int v : b) {
            for (int i = 4; i >= 1; --i) {
                f[i] = max(f[i], f[i - 1] + a[i - 1] * 1ll * v);
            }
        }
        return f.back();

        /*
            记忆化搜索
        */
        // int n = b.size();
        //
        // vector memo(4, vector<ll>(n, LLONG_MIN / 2));
        // auto dfs = [&](auto&& dfs, int i, int j) -> ll {
        //     if (i < 0) {
        //         return 0;
        //     }
        //     if (j < 0) {
        //         return LLONG_MIN / 2;
        //     }
        //
        //     ll& res = memo[i][j];
        //     if (res != LLONG_MIN / 2) {
        //         return res;
        //     }
        //     return res = max(dfs(dfs, i - 1, j - 1) + a[i] * 1ll * b[j], dfs(dfs, i, j - 1));
        // };
        //
        // return dfs(dfs, 3, n - 1);
    }
};

int main() {
    Solution sol;

    return 0;
}