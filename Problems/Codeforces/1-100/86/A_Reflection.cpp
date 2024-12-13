// Date: 2024-12-13  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    ll l, r;
    cin >> l >> r;

    ll x = 1;
    while (x <= r) {
        x *= 10;
    }
    x--;

    ll n = x / 2;
    ll v = min(max(l, n), r);
    cout << v * (x - v) << "\n";
    // if (n <= l) {
    //     cout << l * (x - l) << "\n";
    // } else if (n >= r) {
    //     cout << r * (x - r) << "\n";
    // } else {
    //     cout << n * (x - n) << "\n";
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}