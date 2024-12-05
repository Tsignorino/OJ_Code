// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    vector<map<char, int>> r(n), c(m);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            r[i][g[i][j]]++;
            c[j][g[i][j]]++;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (r[i].size() == 1) {
            q.emplace(0, i);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (c[i].size() == 1) {
            q.emplace(1, i);
        }
    }

    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            auto [x, u] = q.front();
            q.pop();
            if (x == 0) {
                r[u].clear();
                for (int i = 0; i < m; ++i) {
                    if (g[u][i] != '.') {
                        if (--c[i][g[u][i]] == 0) {
                            c[i].erase(g[u][i]);
                        }
                    }
                    g[u][i] = '.';
                }
            } else {
                c[u].clear();
                for (int i = 0; i < n; ++i) {
                    if (g[i][u] != '.') {
                        if (--r[i][g[i][u]] == 0) {
                            r[i].erase(g[i][u]);
                        }
                    }
                    g[i][u] = '.';
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (r[i].size() == 1 && r[i].begin()->second >= 2) {
                q.emplace(0, i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (c[i].size() == 1 && c[i].begin()->second >= 2) {
                q.emplace(1, i);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += g[i][j] != '.';
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