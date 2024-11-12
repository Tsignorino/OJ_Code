#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll l, r;
    cin >> l >> r;
    l--;

    auto f = [&](ll n) {
        if (n < 10) {
            return n;
        }
        ll res = 9 + n / 10;
        if (to_string(n)[0] - '0' > n % 10) {
            res--;
        }
        return res;
    };

    cout << f(r) - f(l) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}