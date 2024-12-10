// Date: 2024-12-10  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> d(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        d[l]++, d[r]--;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + d[i];
    }

    ranges::sort(pre);
    ranges::sort(a);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * pre[i + 1];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}