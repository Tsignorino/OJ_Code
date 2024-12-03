// Date: 2024-12-03  星期二

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

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    if (ranges::is_sorted(a)) {
        cout << 0 << "\n";
        return;
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i]);
        if (mx == i + 1 && a[i] == i + 1) {
            cout << 1 << "\n";
            return;
        }
    }

    int p = find(a.begin(), a.end(), 1) - a.begin();
    int q = find(a.begin(), a.end(), n) - a.begin();
    if (p == n - 1 && q == 0) {
        cout << 3 << "\n";
    } else {
        cout << 2 << "\n";
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