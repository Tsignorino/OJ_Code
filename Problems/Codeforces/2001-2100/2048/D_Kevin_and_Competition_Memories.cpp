// Date: 2024-12-20  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int inf = numeric_limits<int>::max() / 2;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
        v = max(v, a[0]);
    }
    vector<int> b(m);
    for (int& v : b) {
        cin >> v;
        if (v <= a[0]) {
            v = inf;
        }
    }

    ranges::sort(a);
    ranges::sort(b, greater<>());

    for (int& v : b) {
        v = a.end() - ranges::lower_bound(a, v);
    }

    for (int k = 1; k <= m; ++k) {
        ll ans = 0;
        for (int i = k; i <= m; i += k) {
            ans += b[i - 1] + 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
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