#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    操作相邻元素考虑连续子数组
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    // dp[i][j]：前 i 个数字使用 j 次操作的最小和
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, LLONG_MAX / 2));
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j] + vec[i];

            int minV = vec[i];
            for (int k = 1; k <= j && i - k - 1 >= 0; ++k) {
                minV = min(minV, vec[i - k]);
                dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + minV * 1ll * (k + 1));
            }
        }
    }

    cout << dp[n][m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}