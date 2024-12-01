// Date: 2024-12-01  星期天

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

    vector<string> g(n);
    for (auto& s : g) {
        cin >> s;
    }

    vector vis(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '?') {
                vis[i][j] = 1;
            }
        }
    }

    vector f(n, vector<int>(m));
    auto check = [&](this auto&& check, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && f[x][y] == 0;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) {
                continue;
            }
            int x = i, y = j;
            vector<pair<int, int>> path;
            while (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0) {
                vis[x][y] = 1;
                path.emplace_back(x, y);
                if (g[x][y] == 'U') {
                    x--;
                } else if (g[x][y] == 'D') {
                    x++;
                } else if (g[x][y] == 'L') {
                    y--;
                } else {
                    y++;
                }
            }
            if (check(x, y) == 0) {
                for (auto& [x, y] : path) {
                    f[x][y] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '?') {
                if ((check(i - 1, j) || check(i + 1, j) || check(i, j - 1) || check(i, j + 1)) == 0) {
                    f[i][j] = 1;
                }
            }
        }
    }

    int ans = n * m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans -= f[i][j];
        }
    }
    cout << ans << "\n";
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