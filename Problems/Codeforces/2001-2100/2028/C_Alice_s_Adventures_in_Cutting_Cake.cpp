// Date: 2024-12-11  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> a(n);
    vector<ll> pre {0};
    ll sum = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        s += a[i];
        if (s >= v) {
            pre.emplace_back(sum);
            s = 0;
        }
    }
    if (pre.size() <= m) {
        cout << -1 << "\n";
        return;
    }

    ll ans = sum - pre[m];
    s = 0;
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
        sum -= a[i];
        s += a[i];
        if (s >= v) {
            ans = max(ans, sum - pre[j--]);
            s = 0;
        }
    }
    cout << ans << "\n";
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