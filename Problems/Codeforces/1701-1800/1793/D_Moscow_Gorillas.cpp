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

    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[v] = i;
    }

    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        b[v] = i;
    }

    int i = a[1], j = b[1];
    int l1 = i, r1 = i;
    int l2 = j, r2 = j;
    if (i > j) {
        swap(i, j);
    }

    // 不含 1 的方案数与整个数组的方案数
    ll ans = i * 1ll * (i + 1) / 2 + (j - i - 1) * 1ll * (j - i) / 2 + (n - j - 1) * 1ll * (n - j) / 2 + 1;
    for (int v = 2; v <= n; ++v) {
        int i = a[v], j = b[v];
        if (!(l1 < i && i < r1 || l2 < j && j < r2)) {
            int l = -1;
            if (i < l1) {
                l = i;
            }
            if (j < l2) {
                l = max(l, j);
            }

            int r = n;
            if (i > r1) {
                r = i;
            }
            if (j > r2) {
                r = min(r, j);
            }

            ans += max(min(l1, l2) - l, 0) * 1ll * max(r - max(r1, r2), 0);
        }
        l1 = min(l1, i);
        r1 = max(r1, i);
        l2 = min(l2, j);
        r2 = max(r2, j);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}