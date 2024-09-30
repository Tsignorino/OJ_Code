#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    ll m, x;
    cin >> m >> x;
    vector<int> c(m), h(m);
    for (int i = 0; i < m; i += 1) {
        cin >> c[i] >> h[i];
    }

    int sh = accumulate(h.begin(), h.end(), 0);

    vector<ll> f(sh + 1, LLONG_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = sh; j >= h[i]; --j) {
            ll w = f[j - h[i]] + c[i];
            if (w <= i * x) {
                f[j] = min(f[j], w);
            }
        }
    }

    for (int i = sh; i >= 0; --i) {
        if (f[i] != LLONG_MAX / 2) {
            cout << i << "\n";
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
