// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int q, h;
    cin >> q >> h;

    while (q--) {
        ll x, y, z;
        cin >> x >> y >> z;
        z = h * 2 - z;

        ll g = gcd(gcd(x, y), z);
        cout << x / g << " " << y / g << " " << z / g << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}