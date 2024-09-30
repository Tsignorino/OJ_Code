#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector dp(n + 1, vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
            if (s[l] == s[r]) {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            } else {
                for (int k = l; k < r; ++k) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}