// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    constexpr int inf = 1e9;

    int n = a.size(), m = b.size();
    vector f(n + 1, vector<int>(m + 1, inf));
    f[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n) {
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + (a[i] != c[i + j]));
            }
            if (j < m) {
                f[i][j + 1] = min(f[i][j + 1], f[i][j] + (b[j] != c[i + j]));
            }
        }
    }
    cout << f[n][m] << "\n";
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