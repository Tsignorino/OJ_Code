#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, p, q;
    cin >> n >> p >> q;

    vector dp(n + 1, vector<int>(p + 1, q + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        for (int j = i; j >= 0; --j) {
            for (int k = p; k >= a; --k) {
                dp[j + 1][k] = min(dp[j + 1][k], dp[j][k - a] + b);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= p; ++j) {
            if (dp[i][j] <= q) {
                ans = max(ans, i + 1);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}