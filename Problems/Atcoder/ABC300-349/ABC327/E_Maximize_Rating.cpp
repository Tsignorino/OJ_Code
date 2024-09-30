#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int& v : p) {
        cin >> v;
    }

    vector<double> dp(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            dp[j + 1] = max(dp[j + 1], dp[j] * 0.9 + p[i]);
        }
    }

    double ans = -1200, d = 0;
    for (int i = 1; i <= n; i++) {
        d = d * 0.9 + 1;
        ans = max(ans, dp[i] / d - 1200 / sqrt(i));
    }
    cout << fixed << setprecision(15) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}