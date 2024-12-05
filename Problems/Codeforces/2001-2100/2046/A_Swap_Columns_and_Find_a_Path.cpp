// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    int sum = 0, mx = -inf;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        sum += max(v, a[i]);
        mx = max(mx, min(v, a[i]));
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