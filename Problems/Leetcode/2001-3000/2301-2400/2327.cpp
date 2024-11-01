#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
    static constexpr int MOD = 1'000'000'007;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        /*
            刷表法
        */
        // vector<int> f(n);
        // f[0] = 1;
        // int cnt = 0;
        // for (int i = 0; i < n; ++i) {
        //     if (i + delay >= n) {
        //         cnt = (cnt + f[i]) % MOD;
        //     }
        //     for (int j = i + delay; j < min(i + forget, n); ++j) {
        //         f[j] = (f[j] + f[i]) % MOD;
        //     }
        // }
        // return (f[n - 1] + cnt) % MOD;

        /*
            把 (i+delay, i+forget) 中的数加上同一个数，考虑差分优化
        */
        // vector<int> diff(n);
        // diff[0] = 1, diff[1] = -1 + MOD;
        // int c1 = 0, c2 = 0;
        // for (int i = 0; i < n; ++i) {
        //     c1 = (c1 + diff[i]) % MOD;
        //     if (i + delay >= n) {
        //         c2 = (c2 + c1) % MOD;
        //     } else {
        //         diff[i + delay] = (diff[i + delay] + c1) % MOD;
        //         if (i + forget < n) {
        //             diff[i + forget] = (diff[i + forget] - c1 + MOD) % MOD;
        //         }
        //     }
        // }
        // return (c1 + c2) % MOD;

        /*
            查表法，前缀和优化
        */
        vector<int> sum(n + 1);
        sum[0] = 0, sum[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int v = (sum[max(i - delay, 0)] - sum[max(i - forget, 0)] + MOD) % MOD;
            sum[i] = (sum[i - 1] + v + MOD) % MOD;
        }
        return ((sum[n] - sum[max(n - forget, 0)]) % MOD + MOD) % MOD;
    }
};

int main() {
    Solution sol;

    return 0;
}