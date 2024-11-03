#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (auto& s : g) {
        cin >> s;
    }

    int ans = 0;
    for (int r = 0; r * 2 <= min(n, m) - 1; ++r) {
        string t;
        for (int i = r + 1; i < m - r; ++i) {
            t.push_back(g[r][i]);
        }
        for (int i = r + 1; i < n - r; ++i) {
            t.push_back(g[i][m - 1 - r]);
        }
        for (int i = m - 2 - r; i >= r; --i) {
            t.push_back(g[n - 1 - r][i]);
        }
        for (int i = n - 2 - r; i >= r; --i) {
            t.push_back(g[i][r]);
        }
        t += t.substr(0, 3);
        for (int i = 0; i < t.size(); ++i) {
            ans += t.substr(i, 4) == "1543";
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