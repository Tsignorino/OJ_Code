// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;
static constexpr int inf = numeric_limits<int>::max() / 2;

void solve() {
    int n;
    cin >> n;

    vector a(n, vector(n, vector<int>(n)));
    for (auto& _ : a) {
        for (auto& _ : _) {
            for (int& v : _) {
                cin >> v;
            }
        }
    }

    vector<int> f(1 << (n * 2), inf);
    f[0] = 0;
    for (int p = 0; p < (1 << (n * 2)); ++p) {
        if (f[p] == inf) {
            continue;
        }
        int i = __popcount(p) / 2;
        for (int j = 0; j < n; ++j) {
            if (p >> j & 1) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (p >> (n + k) & 1) {
                    continue;
                }
                int np = p | 1 << j | 1 << (n + k);
                f[np] = min(f[np], f[p] + a[i][j][k]);
            }
        }
    }
    cout << f.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}