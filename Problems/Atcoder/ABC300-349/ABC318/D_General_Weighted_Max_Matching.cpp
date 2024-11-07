#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> (g[i][j] = g[j][i]);
        }
    }

    vector<ll> dp(1 << n);
    for (int k = 0; k < (1 << n); ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((k >> i) & 1 || (k >> j) & 1) {
                    continue;
                }
                dp[k | (1 << i) | (1 << j)] = max(dp[k | (1 << i) | (1 << j)], dp[k] + g[i][j]);
            }
        }
    }
    cout << dp.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}