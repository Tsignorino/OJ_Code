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

    constexpr int inf = INT_MAX / 2;
    array<int, 3> f {0, -inf, -inf}; // 间隔前，间隔中，间隔后
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        f[2] = max(f[2], f[1]);
        f[1] = max(f[1], f[0]);

        f[2] += (v > f[2]) - (v < f[2]);
        f[0] += (v > f[0]) - (v < f[0]);
    }
    cout << max(f[1], f[2]) << "\n";
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