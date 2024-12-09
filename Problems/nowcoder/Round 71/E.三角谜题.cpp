// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, ll> mp;
    for (int i = 0; i < n; ++i) {
        int v, c;
        cin >> v >> c;
        mp[v] += c;
    }

    int mx1 = 0, mx2 = 0;
    for (auto [v, c] : mp) {
        if (c >= 2) {
            if (v > mx1) {
                mx2 = mx1;
                mx1 = v;
            } else if (v > mx2) {
                mx2 = v;
            }
        }
    }

    long double ans = -1;
    for (auto [v, c] : mp) {
        if (v != mx1 || c >= 3) {
            if (mx1 * 2 <= v) {
                continue;
            }
            ans = max(ans, v * 0.5l * sqrt(mx1 * 1.0l * mx1 - v * 0.5l * v * 0.5l));
        } else {
            if (mx2 * 2 <= v) {
                continue;
            }
            ans = max(ans, v * 0.5l * sqrt(mx2 * 1.0l * mx2 - v * 0.5l * v * 0.5l));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}