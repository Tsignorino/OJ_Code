// Date: 2024-11-24  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x;
    ll m;
    cin >> x >> m;

    int ans = 0;
    for (int y = 1; y <= min(x * 2ll, m); ++y) {
        if (x == y) {
            continue;
        }
        int v = x ^ y;
        if (x % v == 0 || y % v == 0) {
            ans++;
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