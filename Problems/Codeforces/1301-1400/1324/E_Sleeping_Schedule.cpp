// Date: 2024-12-04  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    auto check = [&](int x) {
        return l <= x && x <= r;
    };

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
    dp[0][0] = 0;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        for (int j = 0; j <= n; ++j) {
            // 不早睡
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + check((sum - j) % h));
            // 早睡一小时
            if (j < n) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + check((sum - j - 1) % h));
            }
        }
    }
    cout << ranges::max(dp[n]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}