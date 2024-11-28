// Date: 2024-11-28  星期四

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

    set<int> row, col;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        row.emplace(x), col.emplace(y);
    }

    int r = n - row.size(), c = n - col.size();
    vector f(r + 2, vector<long double>(c + 2));
    for (int i = r; i >= 0; --i) {
        for (int j = c; j >= 0; --j) {
            if (i == r && j == c) {
                continue;
            }
            f[i][j] = (n * n + (r - i) * (c - j) * f[i + 1][j + 1] + (r - i) * (n - c + j) * f[i + 1][j] + (n - r + i) * (c - j) * f[i][j + 1]) / (n * n - (n - r + i) * (n - c + j));
        }
    }
    cout << fixed << setprecision(10) << f[0][0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}