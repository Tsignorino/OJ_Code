// Date: 2024-12-10  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        int f, t;
        cin >> f >> t;
        ans = max(ans, f + min(k - t, 0));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}