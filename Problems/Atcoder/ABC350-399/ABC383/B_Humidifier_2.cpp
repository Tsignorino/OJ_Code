// Date: 2024-12-07  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<string> g(n);
    for (string& s : g) {
        cin >> s;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '#') {
                continue;
            }
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (x == i && y == j || g[x][y] == '#') {
                        continue;
                    }
                    int res = 0;
                    for (int a = 0; a < n; ++a) {
                        for (int b = 0; b < m; ++b) {
                            if (g[a][b] == '.' && (abs(a - i) + abs(b - j) <= d || abs(a - x) + abs(b - y) <= d)) {
                                res++;
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}