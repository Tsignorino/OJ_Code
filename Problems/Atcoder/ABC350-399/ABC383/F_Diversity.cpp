// Date: 2024-12-07  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;

    struct Item {
        int p, u, c;
    };
    vector<Item> a(n);
    for (auto& [p, u, c] : a) {
        cin >> p >> u >> c;
    }

    ranges::sort(a, [&](const Item& a, const Item& b) { return a.c < b.c; });

    vector f(n + 1, vector<ll>(x + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = a[i].p; j <= x; ++j) {
            f[i + 1][j] = f[i][j - a[i].p] + a[i].u;
        }

        int p = i - 1;
        while (p >= 0 && a[p].c == a[i].c) {
            p--;
        }
        for (int j = a[i].p; j <= x; ++j) {
            f[i + 1][j] = max(f[i + 1][j], f[p + 1][j - a[i].p] + a[i].u + k);
        }
        for (int j = 0; j <= x; ++j) {
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        }
    }
    cout << ranges::max(f[n]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}