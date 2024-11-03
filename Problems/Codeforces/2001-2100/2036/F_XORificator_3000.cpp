#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 4i ^ (4i+1) ^ (4i+2) ^ (4i+3) = 0
ll get(ll n) {
    if (n % 4 == 0) {
        return n;
    } else if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    } else {
        return 0;
    }
}

void solve() {
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    l--;

    auto func = [&](ll x) -> ll {
        ll v = (x - k) >> i;
        ll res = get(x) ^ (get(v) << i);
        if (v & 1) {
            res ^= k;
        }
        return res;
    };

    cout << (func(l) ^ func(r)) << "\n";
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