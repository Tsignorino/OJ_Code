#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int mOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<string> g(n);
    for (auto& s : g) {
        cin >> s;
    }

    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            int sum = g[i][j] + g[j][n - 1 - i] + g[n - 1 - i][n - 1 - j] + g[n - 1 - j][i];
            int mx = max({g[i][j], g[j][n - 1 - i], g[n - 1 - i][n - 1 - j], g[n - 1 - j][i]});
            ans += mx * 4 - sum;
        }
    }
    cout << ans << "\n";
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