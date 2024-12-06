// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

ll qpow(ll a, ll b, int p, ll res = 1) {
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = a * res % p;
        }
    }
    return res;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Sol 1:
    // if (b == 0 || a % 2 == 1) {
    //     cout << (c % 2 != d % 2 ? "YES" : "NO") << "\n";
    // } else {
    //     cout << (d % 2 == 1 ? "YES" : "NO") << "\n";
    // }

    // Sol 2:
    int x = a % 2;
    if (b == 0) {
        x = 1;
    }
    if (c % 2 == 0) {
        x = 0;
    }
    cout << ((x + d) % 2 ? "YES" : "NO") << "\n";

    // Sol 3:
    // cout << ((qpow(a, b, 2) * c % 2 + d) % 2 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}