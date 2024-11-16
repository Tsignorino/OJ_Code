#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    ll sum = 0;
    int mx = 0;
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        pre = max(pre, v);
        int d = pre - v;
        sum += d;
        mx = max(mx, d);
    }
    cout << sum + mx << "\n";
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