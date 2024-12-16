// Date: 2024-12-16  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2; // k >= 2

    ll p = 1;
    ll ans = 0;
    while (p <= r2) {
        ans += max(0, min(int(r2 / p), r1) - max(int((l2 + p - 1) / p), l1) + 1);
        p *= k;
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