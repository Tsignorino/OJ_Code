// Date: 2024-12-07  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int ans = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        int t, v;
        cin >> t >> v;

        int d = min(t - pre, ans);
        ans -= d;
        ans += v;
        pre = t;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}