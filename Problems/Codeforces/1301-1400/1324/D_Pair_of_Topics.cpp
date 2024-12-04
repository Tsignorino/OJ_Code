// Date: 2024-12-04  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[i] -= v;
    }

    ranges::sort(a);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a.end() - upper_bound(a.begin() + i + 1, a.end(), -a[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}