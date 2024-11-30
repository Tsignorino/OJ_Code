// Date: 2024-11-30  星期六

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

    vector<string> g(n), w(n);
    vector<string> vec;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        g[i] = a, w[i] = b;
        vec.emplace_back(a);
        vec.emplace_back(b);
    }

    ranges::sort(vec);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    vector<int> G(n), W(n);
    for (int i = 0; i < n; ++i) {
        G[i] = ranges::lower_bound(vec, g[i]) - vec.begin();
        W[i] = ranges::lower_bound(vec, w[i]) - vec.begin();
    }

    vector f(1 << n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        f[1 << i][i] = 1;
    }
    for (int k = 0; k < (1 << n); ++k) {
        for (int lst = 0; lst < n; ++lst) {
            if (f[k][lst] == 0) {
                continue;
            }
            for (int i = 0; i < n; ++i) {
                if (k >> i & 1) {
                    continue;
                }
                if (G[lst] == G[i] || W[lst] == W[i]) {
                    f[k | (1 << i)][i] |= f[k][lst];
                }
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < (1 << n); ++k) {
        for (int i = 0; i < n; ++i) {
            if (f[k][i]) {
                ans = max(ans, __popcount(k));
            }
        }
    }
    cout << n - ans << "\n";
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