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
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            if (g[i][j] < 0) {
                mp[i - j] = max(mp[i - j], -g[i][j]);
            }
        }
    }
    // debug(mp);

    int ans = 0;
    for (auto& [_, v] : mp) {
        ans += v;
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