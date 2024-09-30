#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (ll& v1 : a) {
        cin >> v1;
    }
    vector<ll> minV(a);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        minV[i] = min(minV[i], b[i]);
    }

    vector<ll> suf(n + 1);
    for (int i = n; i > 0; --i) {
        suf[i - 1] = suf[i] + minV[i - 1];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < m; ++i) {
        ans = min(ans, a[i] + suf[i + 1]);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
