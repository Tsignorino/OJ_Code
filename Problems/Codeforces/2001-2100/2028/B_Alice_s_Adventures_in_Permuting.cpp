#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, b, c;
    cin >> n >> b >> c;

    if (c >= n) {
        cout << n << "\n";
    } else if (b == 0) {
        cout << (c < n - 2 ? -1 : n - 1) << "\n";
    } else {
        cout << (n - (n - 1 - c) / b - 1) << "\n";
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