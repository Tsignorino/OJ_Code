// Date: 2024-12-10  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << (1ull << bit_width((r ^ l) * 1ull)) - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}