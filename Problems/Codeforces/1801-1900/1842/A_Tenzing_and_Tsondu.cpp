// Date: 2024-12-17  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        ans += v;
    }
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        ans -= v;
    }

    if (ans > 0) {
        cout << "Tsondu\n";
    } else if (ans < 0) {
        cout << "Tenzing\n";
    } else {
        cout << "Draw\n";
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