#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }

    vector f(n + 1, vector<int>(m + 1, numeric_limits<int>::min() / 2));
    for (int i = 0; i <= m; ++i) {
        f[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {
            for (int k = i - 1; k <= j - 1; k++) {
                f[i][j] = max(f[i][j], f[i - 1][k] + g[i][j]);
            }
        }
    }

    int ans = numeric_limits<int>::min();
    for (int i = n; i <= m; ++i) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << "\n";

    // debug(f);

    vector<int> res;
    for (int i = n; i > 0; --i) {
        int j = i;
        while (f[i][j] != ans) {
            j++;
        }
        ans -= g[i][j];
        res.emplace_back(j);
    }
    ranges::reverse(res);
    for (int& v : res) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}