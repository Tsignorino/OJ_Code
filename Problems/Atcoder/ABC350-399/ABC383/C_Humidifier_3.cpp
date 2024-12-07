// Date: 2024-12-07  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int dx[] = {1, 0, -1, 0};
static constexpr int dy[] = {0, 1, 0, -1};

void solve() {
    int n, m, D;
    cin >> n >> m >> D;

    vector<string> g(n);
    for (string& s : g) {
        cin >> s;
    }

    vector cost(n, vector<int>(m));
    vector vis(n, vector<int>(m));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'H') {
                q.emplace(i, j, 0);
            }
        }
    }
    while (!q.empty()) {
        auto [i, j, d] = q.front();
        q.pop();
        if (d <= D && (vis[i][j] == 0 || vis[i][j] == 1 && d < cost[i][j])) {
            cost[i][j] = d;
            vis[i][j] = 1;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#' && (vis[x][y] == 0 || vis[x][y] == 1 && d + 1 < cost[x][y])) {
                    q.emplace(x, y, d + 1);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) {
                ans++;
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