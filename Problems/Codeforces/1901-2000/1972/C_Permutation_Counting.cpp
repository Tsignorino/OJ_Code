#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    ll l = 0, r = 2e12;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;

        ll res = 0;
        for (ll& v : vec) {
            res += max(mid - v, 0ll);
        }

        (res <= k ? l : r) = mid;
    }

    int cnt = 0;
    for (ll& v : vec) {
        if (v <= l) {
            k -= l - v;
        }
        cnt += v > l;
    }
    cout << (l - 1) * n + 1 + cnt + k << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
