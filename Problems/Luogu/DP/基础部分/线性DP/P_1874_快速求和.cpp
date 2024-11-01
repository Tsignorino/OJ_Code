#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    string s;
    cin >> s;

    int t;
    cin >> t;

    int n = s.size();
    vector f(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            f[i][j] = f[i][j - 1] * 10 + (s[j - 1] - '0');
        }
    }
    // debug(f);

    const ll inf = numeric_limits<ll>::max() / 2;
    vector g(n + 1, vector<ll>(t + 1, inf));
    g[0][0] = -1; // !
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= t; ++j) {
            for (int k = i - 1; k >= 0 && f[k + 1][i] <= t; --k) {
                if (f[k + 1][i] > j) {
                    continue;
                }
                g[i][j] = min(g[i][j], g[k][j - f[k + 1][i]] + 1);
            }
        }
    }
    // debug(g);
    cout << (g[n][t] == inf ? -1 : g[n][t]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}