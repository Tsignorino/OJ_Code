#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    ll s = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        s *= x;
    }

    if (2023 % s == 0) {
        cout << "Yes\n";
        cout << 2023 / s;
        for (int i = 1; i < m; ++i) {
            cout << " 1";
        }
        cout << "\n";
    } else {
        cout << "No\n";
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
