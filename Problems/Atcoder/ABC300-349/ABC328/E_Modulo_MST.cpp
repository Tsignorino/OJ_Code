#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector g(n + 1, vector<ll>(n + 1, -1));
    vector<map<ll, int>> dp(1 << n | 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        g[u][v] = g[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        dp[1 << (i - 1)][0] = 1;
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j <= n; j++) {
            if (i >> (j - 1) & 1) {
                continue;
            }
            for (int k = 1; k <= n; k++)
                if (i >> (k - 1) & 1) {
                    if (g[j][k] == -1) {
                        continue;
                    }
                    for (auto v : dp[i]) {
                        dp[i | (1 << (j - 1))][(v.first + g[j][k]) % k] = 1;
                    }
                }
        }
    }

    ll ans = numeric_limits<ll>::max();
    for (auto v : dp[(1 << n) - 1]) {
        ans = min(ans, v.first);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}