// Date: 2024-11-30  星期六

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

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> pre(n + 1, INT_MAX / 2);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = min(pre[i], a[i]);
    }

    // debug(pre);

    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;

        int lo = 0, hi = n + 1;
        while (lo + 1 < hi) {
            auto mid = lo + (hi - lo) / 2;

            if (pre[mid] <= v) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << (hi == n + 1 ? -1 : hi) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}