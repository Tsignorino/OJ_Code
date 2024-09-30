#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    auto calc = [&](ll x) -> ll {
        ll p = x / n, q = x % n;
        ll res = pre[n] * p;
        if (p + q <= n) {
            res += pre[p + q] - pre[p];
        } else {
            res += pre[p + q - n] + pre[n] - pre[p];
        }
        return res;
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << calc(r) - calc(l - 1) << "\n";
    }
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